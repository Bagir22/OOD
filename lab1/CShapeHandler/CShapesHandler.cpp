#include "CShapesHandler.h"
#include "../CCircleDecorator/CCircleDecorator.h"
#include "regex"
#include "SFML/Graphics.hpp"

const int windowWidth = 1000;
const int windowsHeight = 1000;
const std::string windowTitle = "Shapes";

const std::string findCircle = "CIRCLE: ";
const std::string parseCircle = "C=(-?\\d+),(-?\\d+);\\s+R=(-?\\d+)";

CShapesHandler::CShapesHandler(std::istream &in, std::ostream &out, std::vector<std::shared_ptr<sf::Shape> >& shapes):
        m_in(in),
        m_out(out),
        m_shapes(shapes)
        {
}


void CShapesHandler::Execute()
{
    this->GetShapes();

    this->Write();
    this->Draw();
}

void CShapesHandler::GetShapes()
{
    std::string line;

    while(std::getline(this->m_in, line))
    {
        if (line.find(findCircle) != std::string::npos)
        {
            auto circle = std::make_shared<sf::CircleShape>(GetCircle(line));

            this->m_shapes.push_back(circle);

            auto circleDecorator = new CCircleDecorator(circle);

            //std::cout << circleDecorator->GetArea() << " " << circleDecorator->GetPerimeter() << std::endl;
        }
    }
}

void CShapesHandler::Write()
{

}

void CShapesHandler::Draw()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowsHeight), windowTitle);

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        for (int i = 0; i < this->m_shapes.size(); i++)
        {
            window.draw(*this->m_shapes[i]);
        }
        window.display();
    }
}

sf::CircleShape CShapesHandler::GetCircle(std::string line) {
    std::regex circlePattern(parseCircle);
    std::smatch match;

    std::regex_search(line, match, circlePattern);
    float x = std::stof(match[1]);
    float y = std::stof(match[2]);
    float radius = std::stof(match[3]);
    //std::cout << x << " " << y  << " " << radius << std::endl;

    sf::CircleShape circle = sf::CircleShape(radius);
    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Blue);

    return circle;
}
