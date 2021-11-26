//
// Created by Rory on 26/11/2021.
//

#include "Equation.h"

// I will be using Simpson's Rule to find the integral - https://mathworld.wolfram.com/SimpsonsRule.html
double Equation::integrate(int trig, double n, double f) {
    double columns = 1000;                  // Number of columns for the integration, higher = more accurate. Must be even.
    double width = (upper - lower)/columns; // Width of each column
    double total = 0;                       // Total sum of each column

    // Loops between lower and upper for n columns
    for (double i = 0; i <= columns; i++) {
        double current = (i*width)+lower, temp;
        if (i == 0 || i == columns) {
            // Special case for first and last column
            temp = Function::solve(current);
        } else if ((int)i % 2 == 1) {
            // Odd columns
            temp = 2*Function::solve(current);
        } else {
            // Even columns
            temp = 4*Function::solve(current);
        }

        if (trig != 0) {
            if (trig == 1) {
                temp *= cos(f*n*current);
            } else {
                temp *= sin(f*n*current);
            }
        }

        total += temp;
    }

    return (width/3)*total;
}

// Calculates the fourier series for the equation - https://mathworld.wolfram.com/FourierSeries.html
void Equation::fourier() {
    double T = upper - lower, fundamental = (2*M_PI)/T;

    a0 = integrate(0, 0, 0)/T;

    // Find a/b_n from 1 to numTerms
    for (double i = 1; i <= numTerms; i++) {
        // Integrate the new functions and add result onto end of ab_n vector
        ab_n.push_back(std::make_pair((2/T)*integrate(1, i, fundamental), (2/T)*integrate(2, i, fundamental)));
    }
}

void Equation::printFourier() {
    // Check if fourier has actually been calculated yet
    if (a0 == 0 && ab_n.empty()) fourier();

    double f = (2*M_PI)/(upper-lower), n=1;

    std::cout << "f(x) = " << a0;
    for (auto t : ab_n) {
        // Print cosine/a term then sine/b term.
        std::cout << " + " << t.first << "cos(" << n*f << "x)";
        std::cout << " + " << t.second << "sin(" << n*f << "x)";
        n++;
    }
    std::cout << std::endl;
}

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