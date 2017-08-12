#ifndef POLYGON_H
#define POLYGON_H

#include <array>
#include <cmath>

#include "point.h"

namespace polygon {

    template<size_t N>
    double area(std::array<Point, N>& vertices) {
        // http://www.mathopenref.com/coordpolygonarea.html

        double sum = 0;
        for (size_t i = 0; i < N; i++) {
            const Point& curr = vertices[i];
            const Point& next = vertices[(i+1) % N];
            sum += curr.x * next.y - curr.y * next.x;
        }

        return abs(sum / 2);
    }

    template<size_t N>
    double perimeter(std::array<Point, N>& vertices) {
        double sum = 0;
        for (size_t i = 0; i < N; i++)
            sum += vertices[i].distance(vertices[(i+1) % N]);
        return sum;
    }

    template<size_t N>
    std::pair<Point, Point> boundingBox(std::array<Point, N>& vertices) {
        Point topLeft(vertices[0].x, vertices[0].y);
        Point bottomRight(vertices[0].x, vertices[0].y);

        for (size_t i = 1; i < N; i++) {
            if (vertices[i].x < topLeft.x)
                topLeft.x = vertices[i].x;
            if (vertices[i].x > bottomRight.x)
                bottomRight.x = vertices[i].x;

            if (vertices[i].y > topLeft.y)
                topLeft.y = vertices[i].y;
            if (vertices[i].y < bottomRight.y)
                bottomRight.y = vertices[i].y;
        }

        return std::make_pair(topLeft, bottomRight);
    }
}

#endif // POLYGON_H
