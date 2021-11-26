#include "gui.h"
#include "Equation.h"

#include <iostream>

// TODO: Equation Class
// TODO: Testing

int main() {
    printHeader("Test");
    Equation test("(x+3)^2-5", 10, 0, 1);
    //test.print(); std::cout << std::endl;
    test.fourier();
    test.printFourier();

    return 0;
}