#include "CRectangleDecorator.h"

float CRectangleDecorator::GetArea()
{
    auto area =  m_width * m_height;

    return area;
}

float CRectangleDecorator::GetPerimeter()
{
    auto perimeter = 2 * (m_width + m_height);

    return perimeter;
}

CRectangleDecorator::CRectangleDecorator(const std::shared_ptr<sf::RectangleShape> &shape,
                                         float width, float height) : CShapeDecorator(shape)
{
    m_height = height,
    m_width = width;
}
