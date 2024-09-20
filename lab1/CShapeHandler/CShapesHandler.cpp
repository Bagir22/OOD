#include "CShapesHandler.h"
#include "regex"
#include "SFML/Graphics.hpp"

const int windowWidth = 1000;
const int windowsHeight = 1000;
const std::string windowTitle = "Shapes";

const std::string findCircle = "CIRCLE: ";
const std::string parseCircle = "C=(\\d+),(\\d+);\\s+R=(\\d+)";

const std::string findRectangle = "RECTANGLE: ";
const std::string parseRectangle = "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+)";

const std::string findTriangle = "TRIANGLE: ";
const std::string parseTriangle= "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+);\\s+P3=(\\d+),(\\d+)";

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
        std::cout << line << std::endl;
        if (line.find(findCircle) != std::string::npos)
        {
            auto circle = std::make_shared<sf::CircleShape>(GetCircle(line));

            this->m_shapes.push_back(circle);

            auto circleDecorator = new CCircleDecorator(circle, circle->getRadius());

            std::cout << circleDecorator->GetArea() << " " << circleDecorator->GetPerimeter() << std::endl;
        }
        else  if (line.find(findRectangle) != std::string::npos)
        {
            auto rectangle = std::make_shared<sf::RectangleShape>(GetRectangle(line));

            this->m_shapes.push_back(rectangle);

            auto rectangleDecorator = new CRectangleDecorator
                    (rectangle, rectangle->getSize().x, rectangle->getSize().y);

            std::cout << rectangleDecorator->GetArea() << " " << rectangleDecorator->GetPerimeter() << std::endl;
        }
        else  if (line.find(findTriangle) != std::string::npos)
        {
            auto triangle = std::make_shared<sf::ConvexShape>(GetTriangle(line));

            this->m_shapes.push_back(triangle);

            auto triangleDecorator = new CConvexDecorator
                    (triangle, triangle->getPoint(0), triangle->getPoint(0), triangle->getPoint(0));

            std::cout << triangleDecorator->GetArea() << " " << triangleDecorator->GetPerimeter() << std::endl;
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

        //std::cout << this->m_shapes.size() << std::endl;
        for (int i = 0; i < this->m_shapes.size(); i++)
        {
            window.draw(*this->m_shapes[i]);
        }
        window.display();
    }
}

sf::CircleShape CShapesHandler::GetCircle(std::string line)
{
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

sf::RectangleShape CShapesHandler::GetRectangle(std::string line)
{
    std::regex rectanglePattern(parseRectangle);
    std::smatch match;

    std::regex_search(line, match, rectanglePattern);

    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);

    //std::cout << x1 << " " << y1  << " " << x2 << " " << y2 << std::endl;

    sf::Vector2f points = sf::Vector2f(x1, y1);
    sf::RectangleShape rectangle = sf::RectangleShape();
    rectangle.setPosition(points);

    const float width = abs(x2 - x1);
    const float height = abs(y2 - y1);
    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineColor(sf::Color::Red);

    return rectangle;
}

sf::ConvexShape CShapesHandler::GetTriangle(std::string line) {
    std::regex trianglePattern(parseTriangle);
    std::smatch match;

    std::regex_search(line, match, trianglePattern);
    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);
    float x3 = std::stof(match[5]);
    float y3 = std::stof(match[6]);

    //std::cout << x1 << " " << y1  << " " << x2 << " " << y2 <<  x3 << " " << y3 << std::endl;

    sf::ConvexShape triangle = sf::ConvexShape();
    triangle.setPointCount(3);

    triangle.setPoint(0, sf::Vector2f(x1, y1));
    triangle.setPoint(1, sf::Vector2f(x2, y2));
    triangle.setPoint(2, sf::Vector2f(x3, y3));
    triangle.setFillColor(sf::Color::Magenta);

    return triangle;
}
