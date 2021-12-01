//
// Created by Rory on 26/11/2021.
//

#include "Equation.h"

bool validSpecial(const char &c) {
    // Special characters that can only be part of a string
    const std::vector<char> special = {'+', '-', '*', '/', '^', '(', ')', '.'};

    for (auto s : special) {
        if (s == c) {
            return true;
        }
    }
    return false;
}

// Test that a given equation is valid
bool isEquation(const std::string &s) {
    if (s.empty()) return false;

    if (!isTerm(s)) {
        int brackets = 0, last = 0, open = -1; bool wasOne = false;
        for (int i = 0; i < s.length(); i++) {
            if (!isalnum(s.at(i)) && !validSpecial(s.at(i))) {
                std::cout << "Error: invalid character" << std::endl;
                return false;
            }

            if (s.at(i) == '(') {
                brackets++;
                if (open == -1) {
                    open = i;
                }

                if (open != last) {
                    if (wasOne) {
                        std::cout << "Error: invalid 1 operator term" << std::endl;
                        return false;
                    } else {
                        if (!isDouble(s.substr(last, i-last))) {
                            std::cout << "Error: invalid coefficient" << std::endl;
                            return false;
                        }
                    }
                }
            } else if (s.at(i) == ')') {
                brackets--;

                if (brackets == 0) {
                    if (!isEquation(s.substr(open + 1, i - (open+1)))) {
                        std::cout << "Error: invalid sub-function" << std::endl;
                        return false;
                    } else if (i != s.length() - 1) {
                        if (!is2Operator(s.substr(i + 1, 1))) {
                            std::cout << "Error: no operator after closing bracket" << std::endl;
                            return false;
                        }
                        open = -1;
                        last = i + 1;
                    }
                } else if (brackets < 0) {
                    std::cout << "Error: missing matching close bracket" << std::endl;
                    return false;
                }
            } else if (brackets == 0) {
                // Make sure to check for string overflow later
                if (is2Operator(s.substr(i, 1))) {
                    if (last == i && s.at(i-1) != ')') {
                        std::cout << "Error: consecutive operators found" << std::endl;
                        return false;
                    }
                    std::string group = s.substr(last, i - last);
                    wasOne = false;

                    // Has to be term as Functions involve brackets and are dealt with differently
                    if (!isTerm(group) && !group.empty()) {
                        std::cout << "Error: invalid term" << std::endl;
                        return false;
                    }

                    last = i + 1;
                } else if (is1Operator(s.substr(i, 3))) {
                    if (wasOne) {
                        std::cout << "Error: consecutive 1 term operators found" << std::endl;
                        return false;
                    }

                    wasOne = true;
                    // Move i to the last letter of the 3 letter operator
                    i += 2;
                    last = i+1;
                }

                if (i == s.length() - 1 && last != s.length()) {
                    if(!isTerm(s.substr(last))) {
                        std::cout << "Error: invalid last term" << std::endl;
                        return false;
                    }
                }
            } else if (i == s.length() - 1) {
                std::cout << "Error: unclosed bracket found" << std::endl;
                return false;
            }
        }
    }

    return true;
}

// I will be using Simpson's Rule to find the integral - https://mathworld.wolfram.com/SimpsonsRule.html
double Equation::integrate(int trig, double n, double f) {
    double columns = 1000;                  // Number of columns for the integration, higher = more accurate. Must be even.
    double width = (upper - lower)/columns; // Width of each column
    double total = 0;                       // Total sum of each column

    // Loops between lower and upper for n columns
    for (double i = 0; i <= columns; i++) {
        double current = (i*width)+lower, temp;
        if (i == 0 || i == columns) {
            // Special case for first and last column
            temp = Function::solve(current);
        } else if ((int)i % 2 == 1) {
            // Odd columns
            temp = 4*Function::solve(current);
        } else {
            // Even columns
            temp = 2*Function::solve(current);
        }

        if (trig != 0) {
            if (trig == 1) {
                temp *= cos(f*n*current);
            } else {
                temp *= sin(f*n*current);
            }
        }

        total += temp;
    }

    return (width/3)*total;
}

// Calculates the fourier series for the equation - https://mathworld.wolfram.com/FourierSeries.html
void Equation::fourier() {
    double T = upper - lower, fundamental = (2*M_PI)/T;

    a0 = integrate(0, 0, 0)/T;

    // Find a/b_n from 1 to numTerms
    for (double i = 1; i <= numTerms; i++) {
        // Integrate the new functions and add result onto end of ab_n vector
        ab_n.push_back(std::make_pair((2/T)*integrate(1, i, fundamental), (2/T)*integrate(2, i, fundamental)));
    }
}

std::string Equation::format() {
    std::ostringstream out;
    out.precision();

    // Keeps track of position in terms and in operators respectively
    int t = 0, o = 0;

    while (t < terms.size() && o < operators.size()) {
        if (is2Operator(operators.at(o))) {
            // Only need a special case on the third loop
            if (t == 0 && o == 0) {
                out << terms.at(t)->format() << operators.at(o)  << terms.at(t + 1)->format();
                // t incremented twice for the first loop
                t += 2;
            } else {
                out << operators.at(o) << terms.at(t)->format();
                t++;
            }
        } else if (is1Operator(operators.at(o))) {
            if (operators.at(o) == "lne") {
                out << "ln";
            } else {
                out << operators.at(o);
            }
            out << terms.at(t)->format();
            t++;
        }
        // Increment o
        o++;
    }

    // Prints any left-over terms
    if (t < terms.size()) {
        out << terms.at(t)->format();
    }

    return out.str();
}

std::string Equation::formatFourier() {
    std::ostringstream out;
    out.precision();

    out << a0;

    double f = (2*M_PI)/(upper-lower), n=1;

    for (auto t : ab_n) {
        // Print cosine/a term then sine/b term.

        // Write the correct sign for each term
        if (t.first > 0) out << " + ";
        else out << " - ";
        out << std::abs(t.first) << "cos(" << n*f << "x)";

        if (t.second > 0) out << " + ";
        else out << " - ";
        out << std::abs(t.second) << "sin(" << n*f << "x)";
        n++;
    }

    return out.str();
}

void Equation::saveEquation() {
    std::ofstream output;
    output.open("index.html");

    // Write html file containing the graphs using Desmos api
    output << "<html>"
              " <head>"
              "     <script src=\"https://www.desmos.com/api/v1.6/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6\"></script>"
              " </head>"
              " <body>"
              "     <h3>Base Equation: " << format() <<
              "     <br/>Fourier Equation: " << formatFourier() << "</h3>"
              "     <div id=\"calculator\" style=\"width: 1600px; height: 1200px;\"></div>"
              "     <script>"
              "         var elt = document.getElementById('calculator');"
              "         var calculator = Desmos.GraphingCalculator(elt);"
              "         calculator.setExpression({ id: 'base', latex: 'y=" << format() << "' });"
              "         calculator.setExpression({ id: 'fourier', latex: 'y=" << formatFourier() << "' });"
              "     </script>"
              " </body>";

    output.close();
}
