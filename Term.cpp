//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

Term::Term(std::string inStr) {
    // Remove any lingering whitespace/brackets
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ' '), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), '('), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ')'), inStr.end());
    // Check if last character is a variable - i.e. not a number
    if (!std::isdigit(inStr.at(inStr.length()-1))) {
        var = true;
        if (inStr.length() > 1) {
            coefficient = std::stod(inStr.substr(0, inStr.length() - 1));
        } else {
            coefficient = 1;
        }
    } else {
        var = false;
        coefficient = std::stod(inStr);
    }
}

double Term::solve(double v) {
    if (var) {
        return coefficient * v;
    } else {
        return coefficient;
    }
}

// Add different variable characters later?
void Term::print() {
    if (coefficient != 1) std::cout << coefficient;
    if (var) std::cout << "x";
}
