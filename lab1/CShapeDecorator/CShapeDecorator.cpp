#include "CShapeDecorator.h"
#include "iostream"
#include <SFML/Graphics.hpp>

std::size_t CShapeDecorator::getPointCount() const
{
    return 0;
}

sf::Vector2f CShapeDecorator::getPoint(std::size_t index) const
{
    return sf::Vector2f();
}

CShapeDecorator::CShapeDecorator(std::shared_ptr<sf::Shape> shape) : m_shape(shape)
{
}
