//Серед простих чисел, що не перевищують N, знайти таке,
//у двійковому представленні якого максимальна кількість одиниць.
#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int j = 2; j < n; j++) {
        if (n % j == 0) {
            return false;
        }
    }
    return true;
}

int count_ones(int n) {
    int ones = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            ones++;
        }
        n = n / 2;
    }
    return ones;
}

int main() {
    int n;
    cout << "Enter number N: ";
    cin >> n;

    int best_number = 0;
    int max_ones = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
            int ones = count_ones(i);

            if (ones > max_ones) {
                max_ones = ones;
                best_number = i;
            }
        }
    }
    if (best_number == 0) {
        cout << "No prime numbers found." << endl;
    } else {
        cout << "Prime number: " << best_number << endl;
        cout << "Number of ones in binary: " << max_ones << endl;
    }
    return 0;
}

