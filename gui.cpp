//
// Created by Rory on 23/11/2021.
//

#include "gui.h"

// TODO: Finish this

void printHeader(std::string header) {
    std::cout << getLine(10) << " " << header << " " << getLine(10) << std::endl;
}

/* Planned functions:
    * + - / ()
    Trigonometric functions: sin, cos, tan
    Logarithm: ln, log_
    Exponential: e^, n^
    Powers: x^, sqrt(x)
*/
void printHelp() {

}

std::string getLine(int n) {
    std::string str;
    for (int i = 0; i < n; i++) {
        str.append("-");
    }
    return str;
}
