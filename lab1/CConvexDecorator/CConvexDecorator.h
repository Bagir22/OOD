#include "../CShapeDecorator/CShapeDecorator.h"

class CConvexDecorator: public CShapeDecorator
{
public:
    CConvexDecorator(const std::shared_ptr<sf::ConvexShape> &shape,
                              sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint);

    float GetArea() override;
    float GetPerimeter() override;
private:
    std::vector<float> GetSidesLenght();

    sf::Vector2f m_firstPoint;
    sf::Vector2f m_secondPoint;
    sf::Vector2f m_thirdPoint;
};