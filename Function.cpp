//
// Created by Rory on 23/11/2021.
//

#include "Function.h"

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

char Function::findVariable() {
    return 0;
}

void Function::calculateTerms() {

}

void Function::displayString() {

}

void Function::displayPlot() {

}

bool Function::validateString(std::string &func) {
    return false;
}

double Function::integrate(std::string &func, double l, double u) {
    return 0;
}
