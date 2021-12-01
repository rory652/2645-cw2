#include "gui.h"
#include "Equation.h"
#include "tests.h"

#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 2 && std::string(argv[1]) == "test") {
        printHeader("Testing");
        runTests();
    }
    // Declare functions
    int terms = 0; double lower = 0, upper = 0;
    std::string input;

    printHeader("Help Key");
    printHelp();

    while (!isEquation(input)) {
        printHeader("Enter Equation");
        std::cin >> input;
    }

    while (terms <= 0) {
        printHeader("Enter Number of Fourier Terms");
        std::cin >> terms;
    }

    while (lower >= upper) {
        printHeader("Enter lower bound of period");
        std::cin >> lower;
        printHeader("Enter upper bound of period");
        std::cin >> upper;
    }

    Equation func(input, terms, lower, upper);

    printHeader("Your Equation");
    std::cout << func.format() << std::endl;
    func.fourier();
    printHeader("Fourier Series");
    std::cout << func.formatFourier() << std::endl;

    return 0;
}