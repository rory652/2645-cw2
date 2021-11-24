//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

Term::Term(std::string inStr) {
    // Check if last character is a variable - i.e. not a number
    std::cout << inStr.at(inStr.length()-1) << std::endl;
    if (!std::isdigit(inStr.at(inStr.length()-1))) {
        var = true;
        coefficient = std::stod(inStr.substr(0, inStr.length()-2));
    } else {
        var = false;
        coefficient = std::stod(inStr.substr(0, inStr.length()-1));
    }
}

double Term::solve(double v) {
    if (var) {
        return coefficient * v;
    } else {
        return coefficient;
    }
}
