#include "gui.h"
#include "Equation.h"

#include <iostream>

// TODO: Equation Class
// TODO: Testing

int main() {
    printHeader("Test");
    Equation test("x^2", 1, 0, 1);
    test.print(); std::cout << std::endl;
    std::cout << test.integrate() << std::endl;

    return 0;
}