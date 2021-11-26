//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

Term::Term(std::string inStr) {
    // Remove any lingering whitespace/brackets
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ' '), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), '('), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ')'), inStr.end());
    if (!inStr.empty()) {
        // Check if last character is a variable - i.e. not a number
        if (std::isalpha(inStr.at(inStr.length()-1))) {
            // Add support for 'e' as a constant
            if (inStr.at(inStr.length()-1) == 'e') {
                var = false;
                if (inStr.length() > 1) {
                    coefficient = M_E*std::stod(inStr.substr(0, inStr.length() - 1));
                } else {
                    coefficient = M_E;
                }
            } else {
                var = true;
                if (inStr.length() > 1) {
                    coefficient = std::stod(inStr.substr(0, inStr.length() - 1));
                } else {
                    coefficient = 1;
                }
            }
        } else {
            var = false;
            coefficient = std::stod(inStr);
        }
    } else {
        // Invalid string passed, -1 used as coefficient is always positive
        var = false;
        coefficient = -1;
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
