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

class Function : public Group {
    public:
        Function();
        Function(std::string inStr);
        double solve(double var) override;
    private:
        double coefficient;                         // Coefficient of overall function (if exists)
        std::vector<std::unique_ptr<Group>> terms;  // Vector containing pointers to functions/terms
        std::vector<char> operators;                // Vector containing the operators for terms
};


#endif //INC_2645_CW2_FUNCTION_H
