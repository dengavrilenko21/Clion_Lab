#include <iostream>
using namespace std;

bool Find_sum(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}

int main () {
    int size;
    cout << "Enter the number of elements in the array: ";
    cin >> size;

    const int MAX_SIZE = 1000;
    if (size <= 0 || size > MAX_SIZE) {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        cout << "Enter element " << i  << ":";
        cin >> arr[i];

    }

    int target;
    cout << "Enter target number: ";
    cin >> target;

    if (Find_sum(arr, size, target)) {
        cout << "Yes, target number can be formed by 2 elements from the array." << endl;
    } else {
        cout << "No, target number cannot be formed by 2 elements from the array." << endl;
    }

    return 0;
}

