#pragma once
#include <iostream>
using namespace std;

class Point2D {
private:
    int x;
    int y;
public:

    // Конструктор
    Point2D(int x = 0, int y = 0) : x(x), y(y) {  }

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& out, const Point2D& point) {
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }

    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator==(const Point2D& point) {
        if (x == point.x && y == point.y) return 1;
        else return 0;
    }
};
