#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double px, double py) : x(px), y(py) {}

    friend std::ostream&
    operator<<(std::ostream& st, const Point& point);

    Point
    operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }

    Point
    operator-(const Point& other) {
        return Point(x - other.x, y - other.y);
    }
};

std::ostream&
operator<<(std::ostream& st, const Point& point) {
    return st << "Point(" << point.x << ',' << point.y << ')';
}


int main() {
    Point p1(2,3);
    Point p2(4,5);

    std::cout << p1 << '\n';
    std::cout << p1+p2 << '\n';
    std::cout << p1-p2 << '\n';
    std::cout << p1+p2-p1 << '\n';

}
