/*
 Title: TMA4Question1.cpp
 Description: Solution for Question 1 in TMA4
 Date: August 18, 2017
 Author: Vitor Mendonca
*/

/*
 DOCUMENTATION

 Program Purpose:
    Create and use a hierarchy of classes that perform the functions
    of geometric shapes, in order to study how inheritance works in C++

 Compile (assuming Cygwin is running): make q1
 Execution (assuming Cygwin is running): ./q1

 Notes:
    - In Cygwin, main must return type int
    - Assumes C++11 (see Makefile for reference)

 Classes:
    Point: a class to represent a point in two-dimensional
           space.
    Shape: an abstract class to represent a shape. It
           includes abstract member functions to calculate
           the shape's area, its circumference, and its
           bounding box (represented as a pair of Points)
    Circle: a subclass of Shape that represents a circle.
    Square: a subclass of Shape that represents a four-sided
            polygon.
    Triangle: a subclass of Shape that represents a three-sided
            polygon.

 Variables:
    circle: a Circle instance for testing
    square: a Square instance for testing
    triangle: a Triangle instance for testing
*/

/*
 TEST PLAN

 Normal case:
    >./q1
    >Circle(area: 1661.9, circumference: 144.513, top left: (-13,28), bottom right: (33,-18))
    >Square(area: 207, circumference: 68.4964, top left: (-10,23), bottom right: (5,-5))
    >Triangle(area: 150, circumference: 60.8504, top left: (-15,15), bottom right: (10,0))

 Discussion:
    The main function in this file has the purpose of testing
    the behaviour of the various classes. Test instances are
    created with the start values mentioned in the TMA spec.
    Their data is displayed using their corresponding member
    functions.

    This program takes no input.

*/

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
    points({{p1,p2,p3,p4}}) {}

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
    points({{p1,p2,p3}}) {}

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
