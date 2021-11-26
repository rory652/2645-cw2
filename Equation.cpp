//
// Created by Rory on 26/11/2021.
//

#include "Equation.h"

void Equation::print() {
    // Keeps track of position in terms and in operators respectively
    int t = 0, o = 0;

    while (t < terms.size() && o < operators.size()) {
        if (is2Operator(operators.at(o))) {
            // Only need a special case on the third loop
            if (t == 0 && o == 0) {
                terms.at(t)->print();
                std::cout << operators.at(o);
                terms.at(t + 1)->print();
                // t incremented twice for the first loop
                t += 2;
            } else {
                std::cout << operators.at(o);
                terms.at(t)->print();
                t++;
            }
        } else if (is1Operator(operators.at(o))) {
            std::cout << operators.at(o);
            terms.at(t)->print();
            t++;
        }
        // Increment o
        o++;
    }

    // Prints any left-over terms
    if (t < terms.size()) {
        terms.at(t)->print();
    }
}

// I will be using Simpson's Rule to find the integral - https://mathworld.wolfram.com/SimpsonsRule.html
double Equation::integrate() {
    double columns = 1000;                  // Number of columns for the integration, higher = more accurate. Must be even.
    double width = (upper - lower)/columns; // Width of each column
    double total = 0;                       // Total sum of each column

    // Loops between lower and upper for n columns
    for (double i = 0; i <= columns; i++) {
        double current = (i*width)+lower;
        if (i == 0 || i == columns) {
            // Special case for first and last column
            total += Function::solve(current);
        } else if ((int)i % 2 == 1) {
            // Odd columns
            total += 2*Function::solve(current);
        } else {
            // Even columns
            total += 4*Function::solve(current);
        }
    }

    return (width/3)*total;
}

void Equation::fourier() {

}