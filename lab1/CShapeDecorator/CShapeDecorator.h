#include "SFML/Graphics.hpp"
#include "../CBaseShape/CBaseShape.h"
#include <memory>

#ifndef LAB1_CSHAPEDECORATOR_H
#define LAB1_CSHAPEDECORATOR_H


class CShapeDecorator : public CBaseShape
{
protected:
    std::shared_ptr<CBaseShape> shape;

public:
    CShapeDecorator(std::shared_ptr<CBaseShape> shape) : shape(shape) {}

    double GetArea() const override;

    double GetPerimeter() const override;

    void Draw(sf::RenderWindow& window) const override;

    void WriteToFile(std::ostream& outFile) const override;
};

#endif