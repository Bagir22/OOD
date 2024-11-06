#include "CShapeDecorator.h"
#include "iostream"
#include <SFML/Graphics.hpp>

float CShapeDecorator::GetArea() const
{
    return shape->GetArea();
}

float CShapeDecorator::GetPerimeter() const
{
    return shape->GetPerimeter();
}

void CShapeDecorator::Draw(sf::RenderWindow &window) const
{
    shape->Draw(window);
}

void CShapeDecorator::WriteToFile(std::ostream &outFile) const
{
    shape->WriteToFile(outFile);
}
