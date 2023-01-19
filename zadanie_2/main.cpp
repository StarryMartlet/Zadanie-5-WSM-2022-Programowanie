#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-6; // tolerance for double comparison

struct Point {
    double x, y;
};


double dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); // Distance between two points
}


bool isEquilateral(double a, double b, double c) {
    return fabs(a - b) < EPS && fabs(b - c) < EPS; // Check if the three sides of a triangle are equal
}


bool isIsosceles(double a, double b, double c) {
    return fabs(a - b) < EPS || fabs(b - c) < EPS || fabs(a - c) < EPS; // Check if two sides of a triangle are equal
}


bool isRight(double a, double b, double c) {
    return fabs(pow(a, 2) + pow(b, 2) - pow(c, 2)) < EPS; // Check if the triangle is right
}

string checkShape(Point a, Point b, Point c, Point d) {
    double AB = dist(a, b);
    double BC = dist(b, c);
    double CD = dist(c, d);
    double DA = dist(d, a);
    double AC = dist(a, c);
    double BD = dist(b, d);

    if (fabs(AB - CD) < EPS && fabs(BC - DA) < EPS) {
        if (isRight(AB, BC, AC) || isRight(AB, BC, BD))
            return "rectangle";
        else
            return "trapezoid";
    }

    if (fabs(AB - BC) < EPS && fabs(BC - CD) < EPS && fabs(CD - DA) < EPS && fabs(DA - AB) < EPS)
        return "square";

    if (fabs(AB - CD) < EPS && fabs(BC - DA) < EPS && fabs(AC - BD) < EPS) {
        if (isEquilateral(AB, BC, AC))
            return "equilateral triangle";
        else if (isIsosceles(AB, BC, AC))
            return "isosceles triangle";
        else
            return "scalene triangle";
    }

    return "none of the above";
}

int main() {
    Point a, b, c, d;

    cout << "Enter the x and y coordinates of point A: ";
    cin >> a.x >> a.y;

    cout << "Enter the x and y coordinates of point B: ";
    cin >> b.x >> b.y;

    cout << "Enter the x and y coordinates of point C: ";
    cin >> c.x >> c.y;

    cout << "Enter the x and y coordinates of point D: ";
    cin >> d.x >> d.y;

    string shape = checkShape(a, b, c, d);

    cout << "The shape formed by the given coordinates is a " << shape << endl;

    return 0;
}
