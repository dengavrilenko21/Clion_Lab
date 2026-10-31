//завдання 4
#include <iostream>
using namespace std;
int main() {
    int N , M;
    cout << "Enter rows N: ";
    cin >> N;
    cout << "Enter columns  M: ";
    cin  >> M;

    int matrix [N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    }
    cout << "Matrix :" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j] << " ";

        }
        cout << endl;
    }
    int K;
    cout << "Enter number  K: ";
    cin >> K;
    bool find_K = false;
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j < M; j++ ) {
            if ( matrix[i][j] == K ) {
                cout <<  "The number " << K << " find, its index = [" << i << "][" << j << "]: ";
                find_K = true;
            }
        }
    }
    if ( find_K!=true  ) {
        cout << "The number "<< K << " not found in matrix ";
    }

}