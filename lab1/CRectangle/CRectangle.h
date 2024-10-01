#include "../CBaseShape/CBaseShape.h"

#ifndef LAB1_CRECTANGLE_H
#define LAB1_CRECTANGLE_H

const std::string rectangleStr = "RECTANGLE: ";

class CRectangle: public CBaseShape
{
public:
    CRectangle(std::vector<std::pair<double, double> > points)
    {
        rectangle.setPosition(points[0].first, points[0].second);
        rectangle.setSize(
                sf::Vector2f(abs(points[1].first - points[0].first),
                             abs(points[1].second - points[0].second)));
    }

    double GetArea() const override;

    double GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;
protected:
    sf::RectangleShape rectangle;
};

#endif
