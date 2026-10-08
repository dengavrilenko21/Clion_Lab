#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "Enter a your prime number > N: ";
    cin >> a;

    int best_number = 0;
    int max_ones = 0;

    for (int i = 2; i <= a; i++) {
        bool prime = true;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            int temp = i;
            int ones = 0;
            while (temp > 0) {
                if (temp % 2 == 1) {
                    ones++;
                }
                temp /= 2;
            }

            if (ones > max_ones) {
                max_ones = ones;
                best_number = i;
            }
        }
    }

    if (best_number == 0) {
        cout << "No prime numbers found " << endl;
    } else {
        cout << "Prime number: " << best_number << endl;
        cout << "Number of ones in binary: " << max_ones << endl;
    }

    return 0;
}

