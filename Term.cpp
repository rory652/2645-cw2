//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

// TODO: pi support

// These 2 are for testing
Term::Term() {coefficient=1; var=false;}
Term::Term(double c, bool v) {coefficient=c; var=v;}

Term::Term(std::string inStr) {
    // Remove any lingering whitespace/brackets
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ' '), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), '('), inStr.end());
    inStr.erase(std::remove(inStr.begin(), inStr.end(), ')'), inStr.end());

    int len = inStr.size();
    var = false;    // Assume not a variable

    if (!inStr.empty()) {
        if (std::isalpha(inStr.at(len-1)) && inStr.at(len-1) != 'e' && inStr.at(len-1) != 'i') {
            var = true;
            if (isDouble(inStr.substr(0, len-1))) {
                coefficient = std::stod(inStr.substr(0, len-1));
            } else if (inStr.length()==1) {
                coefficient = 1;
            } else {
                coefficient = -1;
                var = false;
            }
        } else if (inStr.at(len-1) == 'e') {
            if (isDouble(inStr.substr(0, len - 1))) {
                coefficient = M_E * std::stod(inStr.substr(0, len - 1));
            } else if (inStr.substr(0, len - 1).empty()) {
                coefficient = M_E;
            } else {
                coefficient = -1;
            }

            var = false;
        } else if (inStr.at(len-1) == 'i') {
            if (inStr.length() >= 2) {
                if (isDouble(inStr.substr(0, len - 2))) {
                    coefficient = M_PI * std::stod(inStr.substr(0, len - 2));
                } else if (inStr.substr(0, len - 2).empty()) {
                    coefficient = M_PI;
                } else {
                    coefficient = -1;
                }

                var = false;
            } else {
                coefficient = -1;
                var = false;
            }
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

std::string Term::format() {
    std::ostringstream out;
    out.precision();

    if (coefficient != 1 || !var) out << coefficient;
    if (var) out << "x";

    return out.str();
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
