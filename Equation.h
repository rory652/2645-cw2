//
// Created by Rory on 26/11/2021.
//

#ifndef INC_2645_CW2_EQUATION_H
#define INC_2645_CW2_EQUATION_H

#include <fstream>

#include "Function.h"

bool validSpecial(const char &c);      // Checks if a character is a valid special character
bool isEquation(const std::string &s); // Checks if a string is a valid equation

// Class containing the extra information for the equation
class Equation : public Function {
    public:
        // Uses the Function constructor for the actual equation to avoid repeating code
        Equation(const std::string& inStr, int n, double l, double u) : Function(inStr), numTerms(n), lower(l), upper(u), a0(0){};

        /*  trig: selects trig function - 0=none, 1=cosine, 2=sine
         *  n:    value to multiply f by (e.g. current term)
         *  f:    fundamental frequency in radians
         */
        double integrate(int trig, double n, double f); // Integrates the function between the upper and lower bounds
        void fourier();                                 // Finds the values for the fourier series

        std::string format() override;                  // Returns the original equation as a string
        std::string formatFourier();                    // Returns the fourier transform as a string
        void saveEquation();                            // Saves the graph data to a file

        std::pair<double, double> getFourier(int pos) {return ab_n.at(pos);}    // Return the fourier values at pos - ONLY for testing
    private:
        // Extra input values
        int numTerms;           // Number of terms to calculate
        double lower, upper;    // Upper and lower bounds

        // Fourier Values
        double a0;  // Contains a0 values (DC value)
        std::vector<std::pair<double, double>> ab_n;    // Contains all the a/b_n terms for the series
};


#endif //INC_2645_CW2_EQUATION_H
