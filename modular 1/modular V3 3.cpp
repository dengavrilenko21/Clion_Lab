//Завдання 3
#include<iostream>
using namespace std;
int main() {
    long long  n ;
    cout << " Enter number of numbers n: ";
    cin >> n;

    if (n == 0) {
        cout << "Max element = 0 , number of its occurrences = 1 ";
    }
    long long  num;
    cout << "Enter first number:";
    cin >> num;

    long long  max_element = num;
    int count =1;

    for (int i = 2; i <=n; i++) {
        cout  << "Enter the next number:";
        cin >> num;
        if (num > max_element) {
            max_element = num;
            count = 1;
        }else if (num == max_element) {
            count++;
        }



    }
    cout << "Max number: " << max_element << endl;
    cout << "Number of occurrences: " << count << endl;
}
