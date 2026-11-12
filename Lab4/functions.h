
#ifndef CLION_LAB_LAB_4_H
#define CLION_LAB_LAB_4_H


#include <cmath>

double exp(double x, double eps = 0.001) {
    double sum = 0.0;
    double term = 1.0;
    int n = 1;

    while (std::abs(term) >= eps) {
        sum += term;
        term = term * x / n;
        n++;
    }

    return sum;
}

double chx(double x, double eps = 0.001) {
    double sum = 0.0;
    double term = 1.0;
    int k = 0;

    while (std::abs(term) >= eps) {
        sum += term;
        term = term * (x * x) / ((k + 1) * (k + 2));
        k += 2;
    }

    return sum;
}

#endif //CLION_LAB_LAB_4_H