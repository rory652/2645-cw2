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
#include <regex>
#include <algorithm>

class Function : public Group {
    public:
        Function();
        explicit Function(const std::string& inStr);

        double solve(double var) override;
        void print() override;
    private:
        double coefficient;                                 // Coefficient of overall function (if exists)
        std::vector<std::unique_ptr<Group>> terms;          // Vector containing pointers to functions/terms
        std::vector<std::string> operators;                 // Vector containing the operators for terms

        static bool isTerm(std::string str);                // Checks if the string is a term or a group
        static bool is1Operator(const std::string& str);    // Checks if a string is a one term operator or not
        static bool is2Operator(const std::string& str);    // Checks if a string is a two term operator or not
};


#endif //INC_2645_CW2_FUNCTION_H
