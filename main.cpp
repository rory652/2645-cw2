#include "gui.h"
#include "Equation.h"

#include <iostream>

// TODO: Testing

int main() {
    // Declare functions
    int terms; double lower, upper;
    std::string input;

    printHeader("Help Key");
    printHelp();
    printHeader("Enter Equation");
    std::cin >> input;
    printHeader("Enter Number of Fourier Terms");
    std::cin >> terms;
    printHeader("Enter lower bound of period");
    std::cin >> lower;
    printHeader("Enter upper bound of period");
    std::cin >> upper;

    Equation func(input, terms, lower, upper);

    printHeader("Your Equation");
    func.print(); std::cout << std::endl;
    func.fourier();
    printHeader("Fourier Series");
    func.printFourier();

    return 0;
}