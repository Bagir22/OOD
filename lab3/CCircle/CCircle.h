
#include "../CBaseShape/CBaseShape.h"

#ifndef LAB1_CCIRCLE_H
#define LAB1_CCIRCLE_H

const std::string circleStr = "CIRCLE: ";

class CCircle : public CBaseShape
{
public:
    CCircle(float radius, float x, float y)
    {
        circle.setRadius(radius);
        circle.setPosition(x, y);
    }

    float GetArea() const override;

    float GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;

    void Accept(CVisitor &v) const override;
protected:
    sf::CircleShape circle;
};

#endif


