#include <iostream>
using namespace std;
#include <cmath>
struct Point {
    double x;
    double y;
};

Point create_point(double x, double y) {
    Point point;
    point.x = x;
    point.y = y;
    return point;
}
double tringle_area(Point  a , Point b , Point c) {
    return 0.5 * abs((a.x * b.y + a.y * c.x + a.y * b.x * c.y) - (b.y * c.x + a.x * c.y + b.x *a.y));
};

bool point_in_triangle(Point p, Point a, Point b, Point c) {
    double main_area = tringle_area(a, b, c);
    double area1 = tringle_area(p, a, b);
    double area2 = tringle_area(p, b, c);
    double area3 = tringle_area(p, c, a);
    return abs(main_area - (area1 + area2 + area3)) < 1e-7;
}

 int main() {
 Point points[] = {
     create_point(0, 3),
     create_point(3, 0),
     create_point(0, 0),
     create_point(1, 3),
     create_point(2, 1),
     create_point(4, 2),
     create_point(20, 10),
     create_point(3, 42)
 };
    int max_points = -1;
    Point bestA, bestB, bestC;
    int n = sizeof(points) / sizeof(points[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double area = tringle_area(points[i], points[j], points[k]);
                if (area < 1e-9) continue;
                int count = 0;
                for (int m = 0; m < n; m++) {
                    if (point_in_triangle(points[m], points[i], points[j], points[k])) {
                        count++;
                    }
                }
                if (count > max_points) {
                    max_points = count;
                    bestA = points[i];
                    bestB = points[j];
                    bestC = points[k];
                }
            }
        }
    }

    if (max_points == -1) {
        cout << "All points lie on a straight line." << endl;
    } else {
        cout << "Best triangle vertices:" << endl;
        cout << "A(" << bestA.x << "," << bestA.y << ")" << endl;
        cout << "B(" << bestB.x << "," << bestB.y << ")" << endl;
        cout << "C(" << bestC.x << "," << bestC.y << ")" << endl;
        cout << "Max points inside the tringle: " << max_points << endl;
    }
    cout << n << endl;
    return 0;
 }
