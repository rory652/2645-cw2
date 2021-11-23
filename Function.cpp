//
// Created by Rory on 23/11/2021.
//

#include "Function.h"

#include <utility>

Function::Function() {
    inStr = "x";
    terms = 1;
    lower = 0.0;
    upper = 1.0;
}

Function::Function(std::string &in, int n, double l, double u) {
    inStr = in;
    terms = n;
    lower = l;
    upper = u;
}
