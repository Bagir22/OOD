#include <SFML/Graphics.hpp>

#ifndef LAB1_CBASESHAPE_H
#define LAB1_CBASESHAPE_H

class CBaseShape
{
public:
    virtual float GetArea() const = 0;
    virtual float GetPerimeter() const = 0;

    virtual void Draw(sf::RenderWindow& window) const = 0;
    virtual void WriteToFile(std::ostream& outFile) const = 0;
};

#endif
