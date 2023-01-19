#include <iostream>
#include <sstream>
using namespace std;

struct Point {
    float x, y;
    Point(float x, float y) : x(x), y(y) {}
};

void processSquare(string input) {
    stringstream ss(input);
    string token;
    float x1, y1, x2, y2, x3, y3, x4, y4;
    try {
        getline(ss, token, ';'); x1 = stof(token);
        getline(ss, token, ';'); y1 = stof(token);
        getline(ss, token, ';'); x2 = stof(token);
        getline(ss, token, ';'); y2 = stof(token);
        getline(ss, token, ';'); x3 = stof(token);
        getline(ss, token, ';'); y3 = stof(token);
        getline(ss, token, ';'); x4 = stof(token);
        getline(ss, token, ';'); y4 = stof(token);

        if (x1 != x3 || x2 != x4 || y1 != y2 || y3 != y4) {
            cout << "Invalid input. The points do not form a square" << endl;
            return;
        }
        if (x2 - x1 <= 0 || y3 - y1 <= 0) {
            cout << "Invalid input. The side of the square must be a positive value" << endl;
            return;
        }

        Point squareContour[4] = { Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4) };

        for (auto point : squareContour) {
            cout << point.x << ";" << point.y << ";";
        }
        cout << (x2 - x1) * (y3 - y1) << ";";
        cout << "square";
    }
    catch (exception& e) {
        cout << "Invalid input" << endl;
    }
}
void processOtherShape(string input) {
    try {
        stringstream ss(input);
        string token;
        float x1, y1, x2, y2, x3, y3, x4, y4;
        getline(ss, token, ';'); x1 = stof(token);
        getline(ss, token, ';'); y1 = stof(token);
        getline(ss, token, ';'); x2 = stof(token);
        getline(ss, token, ';'); y2 = stof(token);
        getline(ss, token, ';'); x3 = stof(token);
        getline(ss, token, ';'); y3 = stof(token);
        getline(ss, token, ';'); x4 = stof(token);
        getline(ss, token, ';'); y4 = stof(token);

        if (x1 == x4 && x2 == x3 && y1 == y2 && y3 == y4) { // sprawdź, czy dane są kwadratowe
            Point squareContour[4] = { Point(x1, y1), Point(x2, y2), Point(x3, y3), Point(x4, y4) };

            for (auto point : squareContour) { // Wyjście konturu
                cout << point.x << ";" << point.y << ";";
            }

            cout << (x2 - x1) * (y3 - y1) << ";"; //kwadratowy obszar

            cout << "square"; // Wnioskowanie o typie figury
        }
        else {
            cout << " invalid input. The points do not form a square" << endl;
            return;
        }
    }
    catch (exception& e) {
        cout << "Invalid input" << endl;
    }
}
int main() {
    processSquare("1;1;2;1;1;2;2;2;1;4;");
    processOtherShape("1;1;2;1;1;2;2;20;0;0;");
    return 0;
}
//1;1;2;1;1;2;2;2;1;square invalid input. The points do not form a square
//Wyjścia się nie zgadzają, ponieważ w metodzie processSquare wiersz „1;1;2;1;1;2;2;2;1;4;” nie jest prawidłowym wejściem
// dla kwadratu, więc wyprowadzane jest „Nieprawidłowe wejście. Punkty nie tworzą kwadratu”.
// W metodzie processOtherShape dane wejściowe są zatem również wynikiem „Nieprawidłowe dane wejściowe”.