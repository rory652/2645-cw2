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
    testVector.push_back(std::make_unique<Function>());
    testVector.push_back(std::make_unique<Term>(5, true));

    std::cout << testVector.at(0)->solve(10) << std::endl;
    std::cout << testVector.at(1)->solve(10) << std::endl;

    return 0;
}