//
// Created by Rory on 24/11/2021.
//

#ifndef INC_2645_CW2_GROUP_H
#define INC_2645_CW2_GROUP_H

#include <string>

class Group {
    public:
        virtual double solve(double var) = 0;
        virtual std::string format() = 0;

        // Public because it needs to be accessed by other functions
        double coefficient=0;
};


#endif //INC_2645_CW2_GROUP_H
