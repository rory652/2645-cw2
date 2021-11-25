#include "gui.h"

#include "Group.h"
#include "Function.h"

#include <iostream>
#include <vector>
#include <memory>

// TODO: Equation Class
// TODO: Testing

int main() {
    printHeader("Test");
    std::vector<std::unique_ptr<Group>> testVector;
    testVector.push_back(std::make_unique<Function>("sin(x)"));

    testVector.at(0)->print(); std::cout << std::endl;

    std::cout << std::fixed;
    std::cout << testVector.at(0)->solve(10) << std::endl;

    return 0;
}