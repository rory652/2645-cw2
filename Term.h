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
        Term();
        Term(double c, bool v); // Only used in testing
        explicit Term(std::string inStr);

        double solve(double var) override;
        void print() override;
    private:
        bool var;
};


#endif //INC_2645_CW2_TERM_H
