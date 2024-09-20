#include <SFML/Graphics.hpp>
#include "../CShapeDecorator/CShapeDecorator.h"

class CRectangleDecorator: public CShapeDecorator
{
public:
    CRectangleDecorator(const std::shared_ptr<sf::RectangleShape>& shape,
                            float width, float height
                                 );

    float GetArea() override;
    float GetPerimeter() override;
private:
    float m_width;
    float m_height;
};

