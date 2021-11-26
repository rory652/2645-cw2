//
// Created by Rory on 26/11/2021.
//

#include "tests.h"

void runTests() {
    if (termTests()) std::cout << "Term passed all tests" << std::endl;
    exit(0);    // Quit program after testing
}

bool termTests() {
    bool allCorrect = true;
    // Test String:
        // Valid Inputs
        if (!testTerm_String("1", 1)) allCorrect = false;
        if (!testTerm_String("1.1", 1.1)) allCorrect = false;
        if (!testTerm_String("1.117625712653", 1.117625712653)) allCorrect = false;
        if (!testTerm_String("1x", 2)) allCorrect = false;
        if (!testTerm_String("1.1x", 2.2)) allCorrect = false;
        if (!testTerm_String("1.117x", 2.234)) allCorrect = false;
        // Invalid Inputs
        if (!testTerm_String("", -1)) allCorrect = false;
        if (!testTerm_String("1.1.1.1", -1)) allCorrect = false;
        if (!testTerm_String("4xx", -1)) allCorrect = false;
        if (!testTerm_String("x1.23", -1)) allCorrect = false;
        if (!testTerm_String("1x2", -1)) allCorrect = false;
        if (!testTerm_String("", -1)) allCorrect = false;

    // Test Solve:
        // Valid Inputs
        if (!testTerm_Solve(Term(1, false), 1, 1)) allCorrect = false;
        if (!testTerm_Solve(Term(1, true), 1, 1)) allCorrect = false;
        if (!testTerm_Solve(Term(1, true), 4, 4)) allCorrect = false;
        if (!testTerm_Solve(Term(4, true), 1, 4)) allCorrect = false;
        if (!testTerm_Solve(Term(4.567, false), 1, 4.567)) allCorrect = false;
        if (!testTerm_Solve(Term(2.24, true), 2, 4.48)) allCorrect = false;
        if (!testTerm_Solve(Term(1.56, true), 4.29, 6.6924)) allCorrect = false;

    return allCorrect;
}
bool testTerm_String(std::string in, double expected) {
    Term t = Term(in);
    double result = t.solve(2);
    if (result != expected) {
        std::cout << "Input '" << in << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool testTerm_Solve(Term t, double var, double expected) {
    double result = t.solve(1);
    if (result != expected) {
        std::cout << "Input '" << var << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}

bool functionTests() {
    return false;
}
bool testFunction_String(std::string in, double expected) {
    return false;
}
bool testFunction_Solve(Function f, double var, double expected) {
    double result = f.solve(var);
    if (result != expected) {
        std::cout << "Input '" << var << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool test_isDouble(std::string in, bool expected) {
    bool result = isDouble(in);
    if (result != expected) {
        std::cout << "Input '" << in << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}

bool equationTests() {
    return false;
}
bool testEquation_String(std::string in, double expected) {
    return false;
}
bool testEquation_Solve(Equation e, double var, double expected) {
    double result = e.solve(var);
    if (result != expected) {
        std::cout << "Input '" << var << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool testEquation_Integrate(Equation e, double expected) {
    double result = e.integrate(0, 0, 0);   // Just testing that integration works - trig tested by Fourier function
    if (result != expected) {
        std::cout << "Input failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool testEquation_Fourier(Equation e, double var, std::vector<double> expected) {
    return false;
}
