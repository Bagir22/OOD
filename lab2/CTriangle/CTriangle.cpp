#include "CTriangle.h"
#include "iostream"

std::vector<float> CTriangle::getSidesLength() const
{
    float a = std::sqrt(std::pow(triangle.getPoint(1).x - triangle.getPoint(0).x, 2) +
                        std::pow(triangle.getPoint(1).y - triangle.getPoint(0).y, 2));
    float b = std::sqrt(std::pow(triangle.getPoint(2).x - triangle.getPoint(1).x, 2) +
                        std::pow(triangle.getPoint(2).y - triangle.getPoint(1).y, 2));
    float c = std::sqrt(std::pow(triangle.getPoint(0).x - triangle.getPoint(2).x, 2) +
                        std::pow(triangle.getPoint(0).y - triangle.getPoint(2).y, 2));

    std::vector<float> sides;
    sides.push_back(a);
    sides.push_back(b);
    sides.push_back(c);

    return sides;
}

float CTriangle::GetArea() const
{
    float semiperimeter = GetPerimeter() / 2.0;
    std::vector<float> sides = getSidesLength();


    float area = std::sqrt(semiperimeter) *
            std::sqrt(semiperimeter - sides[0]) *
            std::sqrt(semiperimeter - sides[1]) *
            std::sqrt(semiperimeter - sides[2]);

    return area;
}

float CTriangle::GetPerimeter() const
{
    std::vector<float> sides = getSidesLength();

    float perimeter = sides[0] + sides[1] + sides[2];

    return perimeter;
}

void CTriangle::Draw(sf::RenderWindow &window) const
{
    window.draw(triangle);
}

void CTriangle::WriteToFile(std::ostream &outFile) const
{
    outFile << triangleStr;
}
