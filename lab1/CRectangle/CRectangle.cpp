#include "CRectangle.h"

double CRectangle::GetArea() const
{
    double area = rectangle.getSize().x * rectangle.getSize().y;

    return area;
}

double CRectangle::GetPerimeter() const
{
    double width = rectangle.getSize().x;
    double height = rectangle.getSize().y;

    return 2 * (width + height);
}

void CRectangle::Draw(sf::RenderWindow &window) const
{
    window.draw(rectangle);
}

void CRectangle::WriteToFile(std::ostream &outFile) const
{
    outFile << rectangleStr;
}
