#include "CCircleDecorator.h"

float CCircleDecorator::GetArea()
{
    auto area = static_cast<float>(M_PI * pow(m_radius, 2));
    return area;
}

float CCircleDecorator::GetPerimeter()
{
    auto perimeter = static_cast<float>(M_PI * m_radius * 2);
    return perimeter;
}

CCircleDecorator::CCircleDecorator(const std::shared_ptr<sf::CircleShape> &shape, float radius) : CShapeDecorator(shape)
{
    m_radius = radius;
}

