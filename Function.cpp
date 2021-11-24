//
// Created by Rory on 24/11/2021.
//

#include "Function.h"

Function::Function() {
    coefficient = 1;
    terms.push_back(std::make_unique<Term>(4, false));
    terms.push_back(std::make_unique<Function>("test"));
    operators.emplace_back("sqrt");
}

Function::Function(std::string inStr) {
    std::cout << inStr << std::endl;
    // VERY TEMPORARY
    coefficient = 2;
    terms.push_back(std::make_unique<Term>(4, false));
    terms.push_back(std::make_unique<Term>(2, true));
    operators.emplace_back("+");
}

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
