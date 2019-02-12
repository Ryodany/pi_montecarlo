#include "dummy_canvas.h"

void DummyCanvas::addPoint(const Point2D &point)
{
    double distToBorder = std::sqrt(point.x * point.x + point.y * point.y); // Pythagoras
    if (distToBorder <= m_circle.radius)
        m_insideCircle++;
}

Point2D DummyCanvas::generatePoint()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> randX(0, 1);    
    std::uniform_real_distribution<double> randY(0, 1);
    return { randX(gen) * (m_square.side / 2), randY(gen) * (m_square.side / 2) };
}