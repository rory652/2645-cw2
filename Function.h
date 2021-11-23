//
// Created by Rory on 23/11/2021.
//

#ifndef INC_2645_FUNCTION_H
#define INC_2645_FUNCTION_H

#include <string>
#include <vector>

class Function {
    public:
        // Default Constructor
        Function();
        // Expected Constructor
        Function(std::string &in, int n, double l, double u);
    private:
        // Input Values
        std::string inStr;
        int terms;
        double lower, upper;
        // Output Values
        double a0 = 0;
        std::vector<double> a_n, b_n;
};


#endif //INC_2645_FUNCTION_H
