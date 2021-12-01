//
// Created by Rory on 24/11/2021.
//

#ifndef INC_2645_CW2_FUNCTION_H
#define INC_2645_CW2_FUNCTION_H

#include "Group.h"
#include "Term.h"

#include <memory>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>

// Checks if an operator has a higher priority than the other
bool isPriority(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
// Checks if the string is a term or a group
bool isTerm(std::string str);
// Checks if a string is a one term operator or not
bool is1Operator(const std::string& str);
// Checks if a string is a two term operator or not
bool is2Operator(const std::string& str);

class Function : public Group {
    public:
        Function();
        explicit Function(const std::string& inStr);

        double solve(double var) override;
        std::string format() override;
    protected:
        std::vector<std::unique_ptr<Group>> terms;          // Vector containing pointers to functions/terms
        std::vector<std::string> operators;                 // Vector containing the operators for terms

        std::vector<std::pair<std::string, int>> sortOperators();           // Sorts the vector of operators to be in the order operations
};


#endif //INC_2645_CW2_FUNCTION_H
