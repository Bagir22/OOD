#include "CDrawDecorator.h"

void CDrawDecorator::Draw(sf::RenderWindow &window) const
{
    CShapeDecorator::Draw(window);
}
