#include "iostream"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

#ifndef CSHAPEDECORATOR_H
#define CSHAPEDECORATOR_H

class CShapeDecorator : public sf::Shape
{
public:
    explicit CShapeDecorator(std::shared_ptr<sf::Shape> shape);

    virtual float GetArea() = 0;
    virtual float GetPerimeter() = 0;

    std::size_t getPointCount() const override;
    sf::Vector2f getPoint(std::size_t index) const override;
private:
    std::shared_ptr<sf::Shape> m_shape;
};

#endif // CSHAPEDECORATOR_H
