//
// Created by Rory on 24/11/2021.
//

#include "Term.h"

double Term::solve(double v) {
    if (var) {
        return coefficient * v;
    } else {
        return coefficient;
    }
}
