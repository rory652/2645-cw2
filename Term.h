//
// Created by Rory on 24/11/2021.
//

#ifndef INC_2645_CW2_TERM_H
#define INC_2645_CW2_TERM_H

#include "Group.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>

// Checks if the string is a double - e.g. 7.12345
bool isDouble(const std::string& s);

class Term : public Group {
    public:
        Term() : coefficient(1), var(false) {};
        Term(double c, bool v) : coefficient(c), var(v) {}; // Only used in testing
        explicit Term(std::string inStr);

        double solve(double var) override;
        void print() override;

        // Public because it needs to be accessed by other functions
        double coefficient;
    private:
        bool var;
};


#endif //INC_2645_CW2_TERM_H
