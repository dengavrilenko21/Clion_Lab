#include <iostream>
using namespace std;
int main() {

    long long  a , b , c , d;
    cout << "Enter an integer : ";
    cin >> a;
    cout <<  a << "=";
    while  (a % 2 == 0) {
        a = a / 2;
        if (a == 1) {
            cout << "2";
        } else {
            cout << "2*";
        }
    }

    for ( int i = 3 ; i <= a ; i+= 2) {
        while  (a % i == 0) {
            a = a / i;
            if (a == 1) {
                cout << i;
            }else {
                cout <<i << "*";
            }
        }
    }



    return 0;
}
