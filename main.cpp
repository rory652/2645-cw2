#include "gui.h"

#include "Group.h"
#include "Term.h"

#include <iostream>
#include <vector>
#include <memory>

int main() {
    printHeader("Test");
    std::vector<std::unique_ptr<Group>> testVector;
    std::unique_ptr<Group> test(new Term(4, true));
    std::unique_ptr<Group> test2(new Term(10, false));

    testVector.push_back(std::move(test));
    testVector.push_back(std::move(test2));

    std::cout << testVector.at(0)->solve(10) << std::endl;
    std::cout << testVector.at(1)->solve(10) << std::endl;

    return 0;
}