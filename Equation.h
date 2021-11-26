//
// Created by Rory on 26/11/2021.
//

#ifndef INC_2645_CW2_EQUATION_H
#define INC_2645_CW2_EQUATION_H

#include "Function.h"
// Class containing the extra information for the equation
class Equation : public Function {
    public:
        // Uses the Function constructor for the actual equation to avoid repeating code
        Equation(std::string inStr, int n, double l, double u) : Function(inStr), numTerms(n), lower(l), upper(u){};

        void print();
        double integrate(); // Integrates the function between the upper and lower bounds
        void fourier();     // Finds the values for the fourier series
    private:
        // Extra input values
        int numTerms;           // Number of terms to calculate
        double lower, upper;    // Upper and lower bounds

        // Fourier Values
        double a0;  // Contains a0 values (DC value)
        std::vector<std::pair<double, double>> ab_n;    // Contains all the a/b_n terms for the series
};


#endif //INC_2645_CW2_EQUATION_H
