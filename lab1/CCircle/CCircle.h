
#include "../CBaseShape/CBaseShape.h"

#ifndef LAB1_CCIRCLE_H
#define LAB1_CCIRCLE_H

const std::string circleStr = "CIRCLE: ";

class CCircle : public CBaseShape
{
public:
    CCircle(double radius, double x, double y)
    {
        circle.setRadius(radius);
        circle.setPosition(x, y);
    }

    double GetArea() const override;

    double GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;
protected:
    sf::CircleShape circle;
};

#endif


