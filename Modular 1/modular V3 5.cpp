//Завдання 5
#include <iostream>
using namespace std;
int main() {
    int a;
    cout << "Enter the number: ";
    cin >> a;

    if ( a <0 ) {
        cout << "The number " << a << " is not a palindrome ";
    }else {
        int reversed_a = 0;
        int original_a = a;
        while (a>0 ) {
            int last_digits = a % 10;
            reversed_a = reversed_a * 10 + last_digits;
            a = a / 10;
        }
        if ( reversed_a == original_a ) {
            cout << "The number " << original_a << " is a palindrome";
        }else {
            cout << "The number " << original_a << " is not a palindrome";
        }
    }

}
