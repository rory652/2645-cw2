//
// Created by Rory on 24/11/2021.
//

#ifndef INC_2645_CW2_GROUP_H
#define INC_2645_CW2_GROUP_H

class Group {
    public:
        virtual double solve(double var) = 0;
        virtual void print() = 0;

        // Public because it needs to be accessed by other functions
        double coefficient;
};


#endif //INC_2645_CW2_GROUP_H
