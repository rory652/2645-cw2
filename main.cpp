#include "gui.h"

#include "Group.h"
#include "Term.h"
#include "Function.h"

#include <iostream>
#include <vector>
#include <memory>

int main() {
    printHeader("Test");
    std::vector<std::unique_ptr<Group>> testVector;
    testVector.push_back(std::make_unique<Function>("sin(2x)+4x-(7x+2)^3"));
    testVector.at(0)->print();
    std::cout << std::endl << testVector.at(0)->solve(4) << std::endl;

    return 0;
}