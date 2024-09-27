#include <SFML/Graphics.hpp>

#ifndef LAB1_CBASESHAPE_H
#define LAB1_CBASESHAPE_H

class CBaseShape
{
public:
    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;

    virtual void Draw(sf::RenderWindow& window) const = 0;
    virtual void WriteToFile(std::ostream& outFile) const = 0;
};

#endif
