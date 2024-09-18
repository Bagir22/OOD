#include "../CShapeDecorator/CShapeDecorator.h"
#include <SFML/Graphics.hpp>

class CCircleDecorator: public CShapeDecorator
        {
public:
    explicit CCircleDecorator(const std::shared_ptr<sf::CircleShape>& shape);

    float GetArea() override;
    float GetPerimeter() override;
private:
    float m_radius;
};

