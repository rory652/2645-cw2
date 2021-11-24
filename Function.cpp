//
// Created by Rory on 24/11/2021.
//

#include "Function.h"

Function::Function() {
    coefficient = 1;
    terms.push_back(std::make_unique<Term>(4, false));
    terms.push_back(std::make_unique<Function>("test"));
    operators.push_back('+');
}

Function::Function(std::string inStr) {
    std::cout << inStr << std::endl;
    // VERY TEMPORARY
    coefficient = 2;
    terms.push_back(std::make_unique<Term>(4, false));
    terms.push_back(std::make_unique<Term>(2, true));
    operators.push_back('+');
}

double Function::solve(double var) {
    double total = 0;
    for (int i = 0; i < terms.size() - 1; i++) {
        if (operators.at(i) == '+') {
            total += terms.at(i)->solve(var) + terms.at(i+1)->solve(var);
        }
    }
    return coefficient * total;
}
