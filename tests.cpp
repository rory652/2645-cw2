//
// Created by Rory on 26/11/2021.
//

#include "tests.h"

void runTests() {
    if (termTests()) std::cout << "Term passed all tests" << std::endl;
    if (functionTests()) std::cout << "Function passed all tests" << std::endl;
    if (equationTests()) std::cout << "Equation passed all tests" << std::endl;
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
        // Valid Inputs - at this point, you can assume that all inputs will be valid.
        if (!testTerm_Solve(Term(1, false), 1, 1)) allCorrect = false;
        if (!testTerm_Solve(Term(1, true), 1, 1)) allCorrect = false;
        if (!testTerm_Solve(Term(1, true), 4, 4)) allCorrect = false;
        if (!testTerm_Solve(Term(4, true), 1, 4)) allCorrect = false;
        if (!testTerm_Solve(Term(4.567, false), 1, 4.567)) allCorrect = false;
        if (!testTerm_Solve(Term(2.24, true), 2, 4.48)) allCorrect = false;
        if (!testTerm_Solve(Term(1.56, true), 4.29, 6.6924)) allCorrect = false;

    // Test isDouble:
        // Valid Inputs
        if (!test_isDouble("1", true)) allCorrect = false;
        if (!test_isDouble("1.123", true)) allCorrect = false;
        if (!test_isDouble("123", true)) allCorrect = false;
        if (!test_isDouble("1123.1387", true)) allCorrect = false;
        // Invalid Inputs
        if (!test_isDouble("", false)) allCorrect = false;
        if (!test_isDouble("word", false)) allCorrect = false;
        if (!test_isDouble("1.1.1.1", false)) allCorrect = false;
        if (!test_isDouble("£1.00", false)) allCorrect = false;
        if (!test_isDouble("400x", false)) allCorrect = false;
        if (!test_isDouble("400xx", false)) allCorrect = false;
        if (!test_isDouble("1,00", false)) allCorrect = false;
        if (!test_isDouble("1.276x.123x", false)) allCorrect = false;
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
    double result = t.solve(var);
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

bool functionTests() {
    bool allCorrect = true;
    // Test String:
        // Valid Inputs
        if (!testFunction_String("1", 1)) allCorrect = false;
        if (!testFunction_String("x", 1)) allCorrect = false;
        if (!testFunction_String("x+1", 2)) allCorrect = false;
        if (!testFunction_String("x-1", 0)) allCorrect = false;
        if (!testFunction_String("x*1", 1)) allCorrect = false;
        if (!testFunction_String("x/2", 0.5)) allCorrect = false;
        if (!testFunction_String("x^2", 1)) allCorrect = false;
        if (!testFunction_String("log(x)", 0)) allCorrect = false;
        if (!testFunction_String("lne(x)", 0)) allCorrect = false;
        if (!testFunction_String("sqr(x)", 1)) allCorrect = false;
        if (!testFunction_String("(x+(x+(x+(x+(x+(x+(x)))))))", 7)) allCorrect = false;
        if (!testFunction_String("sqr(x)-(x^2-4x)^3+3(x+1)^2", 40)) allCorrect = false;
        // Invalid Inputs
        /*
        if (!testFunction_String("", -1)) allCorrect = false;
        if (!testFunction_String("()", -1)) allCorrect = false;
        if (!testFunction_String("x++1", -1)) allCorrect = false;
        if (!testFunction_String("x34+sin()", -1)) allCorrect = false;
        if (!testFunction_String("x^2+(2x-1", -1)) allCorrect = false;*/

    // Test Solve:
        // Valid Inputs - at this point, you can assume that all inputs will be valid.
        if (!testFunction_Solve(Function("3x-1"), 5, 14)) allCorrect = false;
        if (!testFunction_Solve(Function("4x^2"), 8, 256)) allCorrect = false;
        if (!testFunction_Solve(Function("(10x+5)/(4x+2)"), 4, 2.5)) allCorrect = false;
        if (!testFunction_Solve(Function("5(x+2)^3"), 2, 320)) allCorrect = false;
        if (!testFunction_Solve(Function("((((((x)+2x)+3x)+4x)+5x)+6x)^2x"), 1, 441)) allCorrect = false;
        if (!testFunction_Solve(Function("sqr(4x)"), 4, 4)) allCorrect = false;
        if (!testFunction_Solve(Function("sqr(4x-3)+4x*(2x-1)"), 3, 63)) allCorrect = false;
        if (!testFunction_Solve(Function("sqrx"), 4, 2)) allCorrect = false;
    return allCorrect;
}
bool testFunction_String(std::string in, double expected) {
    Function f = Function(in);
    double result = f.solve(1);
    if (result != expected) {
        std::cout << "Input '" << in << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool testFunction_Solve(Function f, double var, double expected) {
    double result = f.solve(var);
    if (result != expected) {
        std::cout << "Input '" << var << "' failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}

// Don't need to test constructor or solve as it uses the code from Function
bool equationTests() {
    bool allCorrect = true;
    // Test Integrate:
        // Valid Inputs - anything invalid will be dealt with at the constructor stage
        if (!testEquation_Integrate(Equation("3x-1", 0, 0, 1), 0.5)) allCorrect = false;
        if (!testEquation_Integrate(Equation("x^2-4x", 0, 4, 7), 27)) allCorrect = false;
        if (!testEquation_Integrate(Equation("(4x+2)^2+log(x)", 0, 1, 3), 212.5361641)) allCorrect = false;
        if (!testEquation_Integrate(Equation("sin(2x)-2", 0, -1, 1), -4)) allCorrect = false;
        if (!testEquation_Integrate(Equation("4*cos(3x)+1/2", 0, 2.5, 4), -1.216097193)) allCorrect = false;
        if (!testEquation_Integrate(Equation("(2x-x^2)+x-1+e", 0, -1.25, 2.5), 7.615431857)) allCorrect = false;

    // Test Fourier:
        // Valid Inputs - at this point, you can assume that all inputs will be valid.
        // For my sanity, I will only be testing small n, but if it works for small n, it will work for all n
        std::vector<std::pair<double, double>> expected;
        expected = {{2.533029592, -1.591549431}, {0.6332573978, -0.7957747155}, {0.2814477323, -0.530516477}};
        if (!testEquation_Fourier(Equation("x^2-4x+3", 3, 0, 5), expected)) allCorrect = false;
        expected.empty();
        expected = {{-0.003626857, -0.4205249818}, {-0.000911844, -0.2103588011}, {-0.000405695, -0.1402512503}};
        if (!testEquation_Fourier(Equation("log(x)+2x", 3, 2, 2.5), expected)) allCorrect = false;
        expected.empty();
        expected = {{3.546241427, -14.25523635}, {-0.8865603569, 7.272750081}, {0.3940268253, -4.866417573}};
        if (!testEquation_Fourier(Equation("(4x+x^2)-(2x+3)^3+12x/2", 3, -0.5, 0.5), expected)) allCorrect = false;
        expected.empty();

    return allCorrect;
}
bool testEquation_Integrate(Equation e, double expected) {
    double result = e.integrate(0, 0, 0);   // Just testing that integration works - trig tested by Fourier function
    double maxTolerance = 0.005; // Tolerate up to 0.5% difference in actual to expected

    if (std::abs((result - expected)/expected) > maxTolerance) {
        std::cout << "Input failed. Should be " << expected << " was " << result << std::endl;
        return false;
    }
    return true;
}
bool testEquation_Fourier(Equation e, std::vector<std::pair<double, double>> expected) {
    e.fourier();
    double maxTolerance = 0.01; // Tolerate up to 1% difference in actual to expected

    for (int i = 0; i < expected.size(); i++) {
        std::pair<double, double> compare = e.getFourier(i), expect = expected.at(i);

        double aDiff = std::abs((compare.first-expect.first)/expect.first);
        double bDiff = std::abs((compare.second-expect.second)/expect.second);

        if (aDiff > maxTolerance || bDiff > maxTolerance) {
            std::cout << "A expected " << expect.first << " A actual " << compare.first << " (" << aDiff << ")" << std::endl;
            std::cout << "B expected " << expect.second << " B actual " << compare.second << " (" << bDiff << ")" << std::endl;
            return false;
        }
    }

    return true;
}
