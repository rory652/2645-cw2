//
// Created by Rory on 23/11/2021.
//

#include "gui.h"

void printHeader(std::string header) {
    int totalLength = 50, sideLength = (totalLength-header.length())/2;
    std::cout << getLine(sideLength) << " " << header << " " << getLine(sideLength) << std::endl;
}

/* Planned functions:
    * + - / ()
    Trigonometric functions: sin, cos, tan
    Logarithm: ln, log_
    Exponential: e^, n^
    Powers: x^, sqrt(x)
*/
void printHelp() {
    std::cout << "'+' - Addition\t\t\t'-' - Subtraction\t\t'*' - Multiplication\t'/' - Division" << std::endl;;
    std::cout << "'lne' - Natural Logarithm\t'log' - Base 2 Logarithm\t'^' - Power\t\t'sqr' - Square Root" << std::endl;
    std::cout << "'sin' - Sine\t\t\t'cos' - Cosine\t\t\t'tan' - Tangent" << std::endl;
}

std::string getLine(int n) {
    std::string str;
    for (int i = 0; i < n; i++) {
        str.append("-");
    }
    return str;
}
