
#include "../CBaseShape/CBaseShape.h"

#ifndef LAB1_CCIRCLE_H
#define LAB1_CCIRCLE_H

const std::string circleStr = "CIRCLE: ";

class CCircle : public CBaseShape
{
    sf::CircleShape circle;
public:
    CCircle(float radius, float x, float y)
    {
        circle.setRadius(radius);
        circle.setPosition(x, y);
    }

    double GetArea() const override;

    double GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;

};

#endif


