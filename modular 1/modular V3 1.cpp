#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int n;
    cout << "Number of triangle:" ;
    cin >> n;

    int min_triangle = 1;
    double min_perimetr = 9999999999999999999;

    for (int i = 1; i <= n; i++) {
        double x1, x2, y1, y2 , x3 , y3 ;
        cout << "Enter coordinates x1 ,y1 :";
        cin >> x1  >> y1 ;
        cout << "Enter coordinates x2 ,y2 : ";
        cin >> x2  >> y2 ;
        cout << "Enter coordinates x3 ,y3 :";
        cin >> x3  >> y3 ;


        double a = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
        double b = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
        double c = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));

        double perimetr = a+b+c;
        if (perimetr < min_perimetr) {
            min_perimetr = perimetr;
            min_triangle = i;
        }
        cout << "Perimetr : " << perimetr << endl;
        cout << "Number og triangle with min perimeter: " << min_triangle << endl;
        cout << "______________________________"<< endl<< endl;
    }

    return 0;
}
