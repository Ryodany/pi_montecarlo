#pragma once
#include <iostream>
#include <random>

struct Point2D
{
    double x;
    double y;

    bool operator==(const Point2D &other)
    {
        return x == other.x && y == other.y;
    }
};

struct Square
{
    double side;
};

struct Circle
{
    double radius;
};

class DummyCanvas
{
public:
    size_t m_points = 0;
    size_t m_insideCircle = 0;
    Square m_square;
    Circle m_circle;

public:
    DummyCanvas(size_t points) : m_points(points) {};
    void addPoint(const Point2D &point);
    Point2D generatePoint();
};