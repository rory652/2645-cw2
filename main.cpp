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
    testVector.push_back(std::make_unique<Function>("(3x-(4x+5))-4x+(2x+1)*5"));
    testVector.at(0)->print();
    //std::cout << testVector.at(0)->solve(4) << std::endl;

    return 0;
}