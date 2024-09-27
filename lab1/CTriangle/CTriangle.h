#include "../CBaseShape/CBaseShape.h"

#ifndef LAB1_CTRIANGLE_H
#define LAB1_CTRIANGLE_H

const std::string triangleStr = "TRIANGLE: ";

class CTriangle : public CBaseShape {
    sf::ConvexShape triangle;
public:
    CTriangle(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint) {
        triangle.setPointCount(3);
        triangle.setPoint(0, firstPoint);
        triangle.setPoint(1, secondPoint);
        triangle.setPoint(2, thirdPoint);
    }

    double GetArea() const override;

    double GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;
private:
    std::vector<double> getSidesLength() const;
};

#endif
