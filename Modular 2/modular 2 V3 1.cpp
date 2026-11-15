#include <iostream>
using namespace std;

int sum_of_digits (int n) {
    if ( n < 0) {
        n = -n;
    }
    if (n < 10) {
        return n;
    }
    return (n % 10) + sum_of_digits(n/10);
}
int main() {
    int n;
    cout << "Enter a number N: ";
    cin >> n;
    cout << sum_of_digits(n) << endl;
}