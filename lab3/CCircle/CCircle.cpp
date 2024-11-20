#include "CCircle.h"

float CCircle::GetArea() const
{
    auto area = static_cast<float>(M_PI * pow(circle.getRadius(), 2));
    return area;
}

float CCircle::GetPerimeter() const
{
    auto perimeter = static_cast<float>(M_PI * circle.getRadius() * 2);
    return perimeter;
}

void CCircle::Draw(sf::RenderWindow &window) const
{
    window.draw(circle);
}

void CCircle::WriteToFile(std::ostream &outFile) const
{
    outFile << circleStr;
}

void CCircle::Accept(CVisitor &v) const {
    v.Visit(*this);
}
