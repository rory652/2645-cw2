//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

Term::Term(std::string inStr) {
    // Remove any lingering whitespace/brackets
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ' '), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), '('), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ')'), inStr.end());

    int len = inStr.size();
    var = false;    // Assume not a variable

    if (!inStr.empty()) {
        if (std::isalpha(inStr.at(len-1)) && inStr.at(len-1) != 'e') {
            var = true;
            if (isDouble(inStr.substr(0, len-1))) {
                coefficient = std::stod(inStr.substr(0, len-1));
            } else if (inStr.substr(0, len-1).empty()) {
                coefficient = 1;
            } else {
                coefficient = -1;
                var = false;
            }
        } else if (inStr.at(len-1) == 'e') {
            if (isDouble(inStr.substr(0, len-1))) {
                coefficient = M_E*std::stod(inStr.substr(0, len-1));
            } else if (inStr.substr(0, len-1).empty()) {
                coefficient = M_E;
            } else {
                coefficient = -1;
                var = false;
            }

            var = false;
        } else {
            if (isDouble(inStr.substr(0, len))) {
                coefficient = std::stod(inStr.substr(0, len));
            } else {
                // No letter and no number -> invalid
                coefficient = -1;
            }
        }
    } else {
        // No letter and no number -> invalid
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
    if (coefficient != 1 || !var) std::cout << coefficient;
    if (var) std::cout << "x";
}

bool isDouble(const std::string& s) {
    // Deal with empty strings
    if (s.empty()) return false;

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
