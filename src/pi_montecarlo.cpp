#include "dummy_canvas.h"

#define CANVAS_SIZE 1000

void pi_montecarlo(const std::vector<size_t> &samples)
{
    for (size_t sample : samples)
    {
        DummyCanvas canvas(sample);
        canvas.m_square = { CANVAS_SIZE };
        canvas.m_circle = { CANVAS_SIZE / 2 };

        for (size_t dotIdx = 0; dotIdx < canvas.m_points; dotIdx++)
            canvas.addPoint(canvas.generatePoint());

        // circle area = pi·r^2
        // square area = side^2 = 4r^2 (4 quadrants of r radius, same radius as its inner circle)
        // areas_ratio = pi·r^2 / 4r^2
        // areas_ratio = pi / 4
        // pi = 4 * areas_ratio
        // pi = 4 * dotsInside / totalDots
        // https://www.youtube.com/watch?v=ELetCV_wX_c
        double pi = 4 * ((double)canvas.m_insideCircle / canvas.m_points);
        std::cout << "Sampling " << sample << ", result: " << pi << 
            " inside: " << canvas.m_insideCircle << " total generated points: " << canvas.m_points << std::endl;
    }
}

int main(int argc, char *argv[])
{
    pi_montecarlo({ 10, 100, 10000, 1000000, 10000000 });

    return 0;
}
