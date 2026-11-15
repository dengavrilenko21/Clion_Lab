#include <iostream>
#include "functions.h"
using namespace std;
int main() {
    double x;
    double eps = 0.001;
    cout << "Enter x: ";
    cin >> x;

    double res_exp = exp(x, eps);
    double std_exp = std::exp(x);


    cout << "e^x:"<<endl;
    cout << "Epsilon: " << eps << endl;
    cout << "My function: " << res_exp  <<endl;;
    cout << "Standard cmath: " << std_exp << endl << endl;;
    double my_chx = chx(x, eps);
    double std_chx = std::cosh(x);

    cout << "ch(x):"<<endl;;
    cout << "Epsilon: " << eps << endl;
    cout << "My function: " << my_chx << endl;;
    cout << "Standard cmath: " << std_chx << endl;;

    return 0;
}
