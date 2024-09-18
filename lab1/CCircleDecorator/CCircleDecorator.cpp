#include "CCircleDecorator.h"

float CCircleDecorator::GetArea()
{
    auto area = static_cast<float>(pow(m_radius, 2) * M_PI);
    return area;
}

float CCircleDecorator::GetPerimeter()
{
    auto perimeter = static_cast<float>(M_PI * 2 * m_radius);
    return perimeter;
}

CCircleDecorator::CCircleDecorator(const std::shared_ptr<sf::CircleShape>& shape) : CShapeDecorator(shape)
{
    m_radius = shape->getRadius();
}

