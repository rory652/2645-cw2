//
// Created by Rory on 24/11/2021.
//

#ifndef INC_2645_CW2_TERM_H
#define INC_2645_CW2_TERM_H

#include "Group.h"

class Term : public Group {
    public:
        Term() : coefficient(1), var(false) {};
        Term(double c, bool v) : coefficient(c), var(v) {};
        double solve(double var) override;
    private:
        double coefficient;
        bool var;
};


#endif //INC_2645_CW2_TERM_H
