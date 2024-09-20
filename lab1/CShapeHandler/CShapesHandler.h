#include "iostream"
#include "SFML/Graphics.hpp"
#include "../CCircleDecorator/CCircleDecorator.h"
#include "../CRectangleDecorator/CRectangleDecorator.h"

class CShapesHandler
        {
public:
    CShapesHandler(std::istream& in, std::ostream& out, std::vector<std::shared_ptr<sf::Shape> >& shapes);

    void Execute();
private:
    void Write();
    void Draw();

    void GetShapes();

    sf::CircleShape GetCircle(std::string line);
    sf::RectangleShape GetRectangle(std::string line);

    std::istream& m_in;
    std::ostream& m_out;

    std::vector<std::shared_ptr<sf::Shape> >& m_shapes;
};
