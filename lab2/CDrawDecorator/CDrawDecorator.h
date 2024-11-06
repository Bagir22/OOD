#include "../CShapeDecorator/CShapeDecorator.h"
#include "../CBaseShape/CBaseShape.h"
#include <memory>

#ifndef LAB1_CDRAWDECORATOR_H
#define LAB1_CDRAWDECORATOR_H


class CDrawDecorator : public CShapeDecorator
{
public:
    CDrawDecorator(std::shared_ptr<CBaseShape> shape) : CShapeDecorator(shape) {}

    void Draw(sf::RenderWindow& window) const override;
};

#endif
