//
// Created by Rory on 24/11/2021.
//

#include "Function.h"

// TODO: Write function that checks for mathematical impossibilities and anything else not already covered.
// TODO: Function coefficients

// Shouldn't really ever be called - here just in case
Function::Function() {
    coefficient = 1;
    terms.push_back(std::make_unique<Term>("x"));
    operators.emplace_back("sqrt");
}

Function::Function(const std::string& inStr) {
    int last = 0, open = -1, brackets = 0;

    for (int i = 0; i < inStr.length(); i++) {
        if (inStr.at(i) == '(') {
            // Check if first open brackets had been found
            if (open == -1) {
                    open = i;
            }
            brackets++;
        } else if (inStr.at(i) == ')') {
            brackets--;
            // Has found the matching close bracket for open
            // Doesn't yet account for function coefficient (difference between last and open?)
            if (brackets == 0) {
                std::string subFunction = inStr.substr(open + 1, i - (open + 1));
                terms.push_back(std::make_unique<Function>(subFunction));
                open = -1;
                last = i + 1;
            }
        }

        // Only check for operators if not currently part of a sub-function
        if (brackets == 0) {
            // Make sure to check for string overflow later
            if (is2Operator(inStr.substr(i, 1))) {
                std::string group = inStr.substr(last, i - last);

                // Has to be term as Functions involve brackets and are dealt with differently
                if (isTerm(group)) {
                    terms.push_back(std::make_unique<Term>(group));
                }

                // TODO: Ensure that if a term/function isn't actually created, the operator isn't added and an error it reported
                operators.emplace_back(inStr.substr(i, 1));
                last = i + 1;
            } else if (is1Operator(inStr.substr(i, 3))) {
                std::string op = inStr.substr(i, 3);
                operators.emplace_back(op);

                // Move i to the last letter of the 3 letter operator
                i += 2;
                last = i+1;
            }

            // Dealing with last character - should only be 2nd part of a 2 part operator
            if (i == inStr.length() - 1 && last != inStr.length()) {
                std::string group = inStr.substr(last, (i-last)+1);
                terms.push_back(std::make_unique<Term>(group));
            }
        }
    }

    // Temporary
    coefficient = 1;
}

double Function::solve(double var) {
    // Creates a vector of operations in the correct order and a vector for results
    auto order = sortOperators();

    // Create a vector containing the solved value for each term and pre-allocating memory
    std::vector<std::pair<int, double>> tempResults; tempResults.reserve(terms.size());
    for (int t = 0; t < terms.size(); t++) {
        tempResults.emplace_back(t, terms.at(t)->solve(var));
    }
    // Store the result from a calculation before it's put into tempResults
    double result;

    // Special case that occasionally happens when inside a 1 term function
    if (operators.empty() && terms.size() == 1) {
        return tempResults.at(0).second;
    } else {
        for (const auto& o : order) {
            if (is1Operator(o.first)) {
                /* Finds where the cumulative value is located - e.g. if an operation is term 0 + term 1 then:
                    * the value of that is stored in tempResults[0].second
                    * tempResults[1].first is set to 0 so that if term 1 is required, the program knows the correct value is stored in tempResults[0]
                */
                int leftPos = o.second;
                while (leftPos != tempResults.at(leftPos).first) {
                    leftPos = tempResults.at(leftPos).first;
                }

                // Do operation
                if (o.first == "sin") {
                    result = sin(tempResults.at(leftPos).second);
                } else if (o.first == "cos") {
                    result = cos(tempResults.at(leftPos).second);
                } else if (o.first == "tan") {
                    result = tan(tempResults.at(leftPos).second);
                } else if (o.first == "lne") {
                    result = log(tempResults.at(leftPos).second);
                } else if (o.first == "log") {
                    // TODO: Any base log?
                    result = log2(tempResults.at(leftPos).second);
                } else if (o.first == "sqr") {
                    result = sqrt(tempResults.at(leftPos).second);
                }

                // Update path to result and the temporary result
                tempResults.at(leftPos).second = result;
                tempResults.at(o.second).first = leftPos;
            } else {
                // Need to find the path for both the left (first) and right (second) terms.
                int leftPos = o.second, rightPos = o.second+1;
                while (leftPos != tempResults.at(leftPos).first || rightPos != tempResults.at(rightPos).first) {
                    leftPos = tempResults.at(leftPos).first;
                    rightPos = tempResults.at(rightPos).first;
                }

                // Do operation
                if (o.first == "+") {
                    result = tempResults.at(leftPos).second + tempResults.at(rightPos).second;
                } else if (o.first == "-") {
                    result = tempResults.at(leftPos).second - tempResults.at(rightPos).second;
                } else if (o.first == "*") {
                    result = tempResults.at(leftPos).second * tempResults.at(rightPos).second;
                } else if (o.first == "/") {
                    result = tempResults.at(leftPos).second / tempResults.at(rightPos).second;
                } else if (o.first == "^") {
                    // TODO: This is wrong, fix
                    result = pow(tempResults.at(leftPos).second, tempResults.at(rightPos).second);
                }

                // Update path to result and the temporary result
                tempResults.at(leftPos).second = result;
                tempResults.at(o.second+1).first = leftPos;
            }
        }
    }

    return coefficient*result;
}

void Function::print() {
    // Keeps track of position in terms and in operators respectively
    int t = 0, o = 0;
    // TODO: Remove brackets on outermost print
    std::cout << "(";

    while (t < terms.size() && o < operators.size()) {
        if (is2Operator(operators.at(o))) {
            // Only need a special case on the third loop
            if (t == 0 && o == 0) {
                terms.at(t)->print();
                std::cout << operators.at(o);
                terms.at(t + 1)->print();
                // t incremented twice for the first loop
                t += 2;
            } else {
                std::cout << operators.at(o);
                terms.at(t)->print();
                t++;
            }
        } else if (is1Operator(operators.at(o))) {
            std::cout << operators.at(o);
            terms.at(t)->print();
            t++;
        }
        // Increment o
        o++;
    }

    // Prints any left-over terms
    if (t < terms.size()) {
        terms.at(t)->print();
    }
    std::cout << ")";
}

/* Valid terms take the form of:
 * <double>
 * <double><char>
 * <char>
 */
bool Function::isTerm(std::string str) {
    // Remove any lingering whitespace/brackets
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());

    if (!str.empty()) {
        if (str.length() > 1) {
            if (std::isalpha(str.at(str.length()-1)) && isDouble(str.substr(0, str.length()-1))) {
                return true;
            } else if (isDouble(str.substr(0, str.length()))) {
                return true;
            }
        } else if (std::isalnum(str.at(0))) {
            // either 'x' or '1'
            return true;
        }
    }
    return false;
}

bool isDouble(std::string s) {
    bool pointFound = false;
    // Loop through string checking each character, returning false
    // if there are multiple decimal points or any other character isn't a digit
    for (auto c : s) {
        if (std::isdigit(c)) {
            continue;
        } else if (c == '.' && !pointFound) {
            pointFound = true;
        } else {
            return false;
        }
    }
    return true;
}

// TODO: Write isFunction function for extra validation

bool Function::is1Operator(const std::string& str) {
    // I gave 3 letter mnemonics to functions that had a name longer/shorter - square root -> sqr and ln -> lne
    return str == "sin" || str == "cos" || str == "tan" || str == "sqr" || str == "log" || str == "lne";
}

bool Function::is2Operator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";
}

/* Order of operations:
 * 1. Brackets - should be handled automatically through recursion
 * 2. Trigonometric Functions - no real standard, so I'm just getting it done first
 * 3. Indices and logarithms
 * 4. Multiplication and division
 * 5. Addition and subtraction
*/
std::vector<std::pair<std::string, int>> Function::sortOperators() {
    std::vector<std::pair<std::string, int>> sorted;

    // Left/only term for each operator
    int left = 0;
    for (const auto& op : operators) {
        if (is2Operator(op)) {
            sorted.emplace_back(op, left);
            left++;
        } else if (is1Operator(op)) {
            sorted.emplace_back(op, left);
        }
    }

    std::sort(sorted.begin(), sorted.end(), &isPriority);

    return sorted;
}

bool isPriority(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    // Map of each operation to it's position in the order of operations
    static std::map<std::string, int> operationOrder {
            {"sin", 2},
            {"cos", 2},
            {"tan", 2},
            {"log", 3},
            {"lne", 4},
            {"sqr", 3},
            {"^", 3},
            {"*", 4},
            {"/", 4},
            {"+", 5},
            {"-", 5}
    };

    return operationOrder[a.first] < operationOrder[b.first];
}

