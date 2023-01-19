#include <iostream>
using namespace std;

bool is_rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // check if the four points are distinct
    if (x1 == x2 && y1 == y2) return false;
    if (x1 == x3 && y1 == y3) return false;
    if (x1 == x4 && y1 == y4) return false;
    if (x2 == x3 && y2 == y3) return false;
    if (x2 == x4 && y2 == y4) return false;
    if (x3 == x4 && y3 == y4) return false;

    // check if opposite sides are parallel and of equal length
    if ((x1 == x2 && x3 == x4 && x1 != x3) || (x1 == x3 && x2 == x4 && x1 != x2)) {
        if ((y1 == y3 && y2 == y4) || (y1 == y4 && y2 == y3)) {
            if ((y2 - y1) == (y4 - y3)) return true;
        }
    }
    if ((y1 == y2 && y3 == y4 && y1 != y3) || (y1 == y3 && y2 == y4 && y1 != y2)) {
        if ((x1 == x3 && x2 == x4) || (x1 == x4 && x2 == x3)) {
            if ((x2 - x1) == (x4 - x3)) return true;
        }
    }
    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    // test input 1) 1;1;2;1;1;2;2;2
    x1 = 1;
    y1 = 1;
    x2 = 2;
    y2 = 1;
    x3 = 1;
    y3 = 2;
    x4 = 2;
    y4 = 2;
    if (is_rectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "1) The coordinates form a rectangle." << endl;
    } else {
        cout << "1) The coordinates do not form a rectangle." << endl;
    }

    // test input 2) 1;1;2;1;1;2;2;20
    x1 = 1;
    y1 = 1;
    x2 = 2;
    y2 = 1;
    x3 = 1;
    y3 = 2;
    x4 = 2;
    y4 = 20;
    if (is_rectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "2) The coordinates form a rectangle." << endl;
    } else {
        cout << "2) The coordinates do not form a rectangle." << endl;
    }

    return 0;
}


