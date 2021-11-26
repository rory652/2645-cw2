//
// Created by Rory on 26/11/2021.
//

#ifndef INC_2645_CW2_TESTS_H
#define INC_2645_CW2_TESTS_H

#include <string>

#include "Group.h"
#include "Term.h"
#include "Function.h"
#include "Equation.h"

void runTests();

bool termTests();                                           // Overall test for 'Term' class
bool testTerm_String(std::string in, double expected);      // Test creating Term with string
bool testTerm_Values(int c, bool v, double expected);       // Test creation just using values
bool testTerm_Solve(int var, double expected);              // Test solving terms

bool functionTests();
bool testFunction_String(std::string in, double expected);
bool testFunction_Solve(int var, double expected);

bool equationTests();
bool testEquation_String(std::string in, double expected);
bool testEquation_Solve(int var, double expected);
bool testEquation_Integrate(Equation e, double expected);           // Test Integration method
bool testEquation_Fourier(int var, std::vector<double> expected);   // Test Fourier method

#endif //INC_2645_CW2_TESTS_H
