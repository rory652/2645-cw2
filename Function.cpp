//
// Created by Rory on 24/11/2021.
//

#include "Function.h"

// Shouldn't really ever be called - will be used for testing
Function::Function() {
    coefficient = 1;
    terms.push_back(std::make_unique<Term>(4, false));
    terms.push_back(std::make_unique<Function>("test"));
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

// Not really working - add order of operations
double Function::solve(double var) {
    double total = 0;
    for (int i = 0; i < terms.size() - 1; i++) {
        // Temporary - would like to improve it at some point
        // 2 term functions (left and right)
        if (operators.at(i) == "+") {
            total += terms.at(i)->solve(var) + terms.at(i+1)->solve(var);
        } else if (operators.at(i) == "-") {
            total += terms.at(i)->solve(var) - terms.at(i+1)->solve(var);
        } else if (operators.at(i) == "*") {
            total += terms.at(i)->solve(var) * terms.at(i+1)->solve(var);
        } else if (operators.at(i) == "/") {
            total += terms.at(i)->solve(var) / terms.at(i+1)->solve(var);
        } else if (operators.at(i) == "^") {
            total += pow(terms.at(i)->solve(var), terms.at(i+1)->solve(var));
        }
        // 1 term functions
        else if (operators.at(i) == "sin") {
            total += sin(terms.at(i)->solve(var));
        } else if (operators.at(i) == "cos") {
            total += cos(terms.at(i)->solve(var));
        } else if (operators.at(i) == "tan") {
            total += tan(terms.at(i)->solve(var));
        } else if (operators.at(i) == "ln") {
            total += log(terms.at(i)->solve(var));
        } else if (operators.at(i) == "log") {
            // Need to figure out how I'm doing base - just 2 for now
            total += log2(terms.at(i)->solve(var));
        } else if (operators.at(i) == "sqrt") {
            total += sqrt(terms.at(i)->solve(var));
        }
    }
    return coefficient * total;
}

void Function::print() {
    // Keeps track of position in terms and in operators respectively
    int t = 0, o = 0;
    // Might be a nicer way - just don't want the outer-most brackets
    if (terms.size() != 1) std::cout << "(";

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
    if (terms.size() != 1) std::cout << ")";
}

bool Function::isTerm(std::string str) {
    // Remove any lingering whitespace/brackets
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());

    std::regex r("[0-9]+\\.?[0-9]*[A-z]?");
    return std::regex_match(str, r);
}

bool Function::is1Operator(const std::string& str) {
    // I gave 3 letter mnemonics to functions that had a name longer/shorter - square root -> sqr and ln -> lne
    return str == "sin" || str == "cos" || str == "tan" || str == "sqr" || str == "log" || str == "lne";
}

bool Function::is2Operator(const std::string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";
}

