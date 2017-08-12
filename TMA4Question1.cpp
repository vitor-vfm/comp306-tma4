#include "point.h"
#include "polygon.h"

struct Shape {

    virtual
    double area() = 0;

    virtual
    double circumference() = 0;

    virtual
    std::pair<Point, Point> boundingBox() = 0;

    void display() {
        auto box = boundingBox();
        std::cout << "(area: " << area() << ", ";
        std::cout << "circumference: " << circumference() << ", ";
        std::cout << "top left: " << box.first << ", ";
        std::cout << "bottom right: " << box.second << ")\n";
    }
};

class Circle : public Shape {
private:
    Point _centre;
    double _radius;

public:
    Circle(Point centre, double radius) : _centre(centre), _radius(radius) {}

    double area() {
        return M_PI * _radius * _radius;
    }

    double circumference() {
        return 2 * M_PI * _radius;
    }

    std::pair<Point, Point> boundingBox() {
        Point topLeft(_centre.x - _radius, _centre.y + _radius);
        Point bottomRight(_centre.x + _radius, _centre.y - _radius);
        return std::make_pair(topLeft, bottomRight);
    }

    void display() {
        std::cout << "Circle";
        Shape::display();
    }

};

class Square : public Shape {
private:
    std::array<Point, 4> points;

public:
    Square(Point p1, Point p2, Point p3, Point p4) :
    /* The points must be in clockwise order */
    points({p1,p2,p3,p4}) {}

    double area() {
        return polygon::area(points);
    }

    double circumference() {
        return polygon::perimeter(points);
    }

    std::pair<Point, Point> boundingBox() {
        return polygon::boundingBox(points);
    }

    void display() {
        std::cout << "Square";
        Shape::display();
    }
};

class Triangle : public Shape {
private:
    std::array<Point, 3> points;

public:
    Triangle(Point p1, Point p2, Point p3) :
    /* The points must be in clockwise order */
    points({p1,p2,p3}) {}

    double area() {
        return polygon::area(points);
    }

    double circumference() {
        return polygon::perimeter(points);
    }

    std::pair<Point, Point> boundingBox() {
        return polygon::boundingBox(points);
    }

    void display() {
        std::cout << "Triangle";
        Shape::display();
    }
};

int main() {
    Circle circle(Point(10,5), 23);
    Square square(Point(-10,7), Point(-6,12), Point(4,23), Point(5,-5));
    Triangle triangle(Point(-15,15), Point(10,10), Point(0,0));

    circle.display();
    square.display();
    triangle.display();
}
