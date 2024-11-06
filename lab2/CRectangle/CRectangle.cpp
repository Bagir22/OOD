#include "CRectangle.h"

float CRectangle::GetArea() const
{
    float area = rectangle.getSize().x * rectangle.getSize().y;

    return area;
}

float CRectangle::GetPerimeter() const
{
    float width = rectangle.getSize().x;
    float height = rectangle.getSize().y;

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
