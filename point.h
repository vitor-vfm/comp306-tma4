#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

struct Point {
    double x;
    double y;

    Point(double px, double py) : x(px), y(py) {}

    friend
    std::ostream& operator<<(std::ostream& st, const Point& point);

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) {
        return Point(x - other.x, y - other.y);
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    double distance(const Point& other) {
        const auto diff = *this - other;
        return sqrt(diff.x * diff. x + diff.y * diff.y);
    }
};

std::ostream&
operator<<(std::ostream& st, const Point& point) {
    return st << '(' << point.x << ',' << point.y << ')';
}

#endif // POINT_H