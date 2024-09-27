#include "CShapeDecorator.h"
#include "iostream"
#include <SFML/Graphics.hpp>

double CShapeDecorator::GetArea() const
{
    return shape->GetArea();
}

double CShapeDecorator::GetPerimeter() const
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
