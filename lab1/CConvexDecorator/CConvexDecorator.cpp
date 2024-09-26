#include "CConvexDecorator.h"

CConvexDecorator::CConvexDecorator(const std::shared_ptr<sf::ConvexShape> &shape,
                                   sf::Vector2f firstPoint, sf::Vector2f secondPoint,
                                   sf::Vector2f thirdPoint) : CShapeDecorator(shape)
{
    m_firstPoint = firstPoint;
    m_secondPoint = secondPoint;
    m_thirdPoint = thirdPoint;
}

float CConvexDecorator::GetArea()
{
    float semiperimeter = GetPerimeter() / 2;
    std::vector<float> sides = GetSidesLenght();

    float area = std::sqrt(semiperimeter *
                           (semiperimeter - sides[0]) *
                           (semiperimeter - sides[1]) *
                           (semiperimeter - sides[2]));

    return area;
}

float CConvexDecorator::GetPerimeter()
{
    std::vector<float> sides = GetSidesLenght();

    float perimeter = sides[0] + sides[1] + sides[2];

    return perimeter;
}

std::vector<float> CConvexDecorator::GetSidesLenght()
{
    float a = std::sqrt(std::pow(m_secondPoint.x - m_firstPoint.x, 2) +
                        std::pow(m_secondPoint.y - m_firstPoint.y, 2));
    float b = std::sqrt(std::pow(m_thirdPoint.x - m_secondPoint.x, 2) +
                        std::pow(m_thirdPoint.y - m_secondPoint.y, 2));
    float c = std::sqrt(std::pow(m_firstPoint.x - m_thirdPoint.x, 2) +
                        std::pow(m_firstPoint.y - m_thirdPoint.y, 2));

    std::vector<float> sides;
    sides.push_back(a);
    sides.push_back(b);
    sides.push_back(c);
    
    return sides;
}
