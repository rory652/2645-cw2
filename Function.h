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

        char findVariable();    // Finds what the program thinks is the variable what's to integrate with respect to
        void calculateTerms();  // Calculates all the necessary terms for the fourier series
        void displayString();   // Displays the fourier series for the function in text form
        void displayPlot();     // Plots the fourier series and original plot on a graph
    private:
        // Input Values
        std::string inStr;
        int terms;
        double lower, upper;
        // Calculated Values
        double a0 = 0;
        char var;
        std::vector<double> a_n, b_n;

        // Private Methods
        bool validateString(std::string &func);                     // Checks that the string is a valid mathematical functions
        double integrate(std::string &func, double l, double u);    // Integrates a function between l and u
};


#endif //INC_2645_FUNCTION_H
