#include "CShapesHandler.h"
#include "regex"
#include "SFML/Graphics.hpp"
#include "../CTriangle/CTriangle.h"
#include "../CCircle/CCircle.h"
#include "../CFileDecorator/CFileDecorator.h"
#include "../CDrawDecorator/CDrawDecorator.h"

const int windowWidth = 1000;
const int windowsHeight = 1000;
const std::string windowTitle = "Shapes";
const int windowBackgroundColor = 14737632;

const std::string parseCircle = "C=(\\d+),(\\d+);\\s+R=(\\d+)";

const std::string parseRectangle = "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+)";

const std::string parseTriangle= "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+);\\s+P3=(\\d+),(\\d+)";

const int precision = 2;

CShapesHandler::CShapesHandler(std::istream &in, std::ostream &out, std::vector<std::shared_ptr<CBaseShape> >& shapes):
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
        if (line.find(circleStr) != std::string::npos)
        {
            auto circle = std::make_shared<CCircle>
                    (GetCircle(line));

            m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(circle)));
        }
        else  if (line.find(rectangleStr) != std::string::npos)
        {
            auto rectangle = std::make_shared<CRectangle>
                    (GetRectangle(line));

            m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(rectangle)));
        }
        else  if (line.find(triangleStr) != std::string::npos)
        {
            auto triangle = std::make_shared<CTriangle>
                    (GetTriangle(line));

            m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(triangle)));
        }
    }
}

void CShapesHandler::Write()
{
    for (int i = 0; i < m_shapes.size(); i++)
    {
        m_shapes[i]->WriteToFile(m_out);
    }
}

void CShapesHandler::Draw()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowsHeight), windowTitle);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(windowBackgroundColor));

        for (int i = 0; i < m_shapes.size(); i++)
        {
            m_shapes[i]->Draw(window);
        }

        window.display();
    }
}

CTriangle CShapesHandler::GetTriangle(std::string line)
{
    std::regex trianglePattern(parseTriangle);
    std::smatch match;

    std::regex_search(line, match, trianglePattern);
    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);
    float x3 = std::stof(match[5]);
    float y3 = std::stof(match[6]);

    auto triangle = CTriangle(sf::Vector2f(x1, y1),
                              sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));

    return triangle;
}

CCircle CShapesHandler::GetCircle(std::string line)
{
    std::regex circlePattern(parseCircle);
    std::smatch match;

    std::regex_search(line, match, circlePattern);
    float x = std::stof(match[1]);
    float y = std::stof(match[2]);
    float radius = std::stof(match[3]);

    auto circle = CCircle(radius, x, y);

    return circle;
}

CRectangle CShapesHandler::GetRectangle(std::string line) {
    std::regex rectanglePattern(parseRectangle);
    std::smatch match;

    std::regex_search(line, match, rectanglePattern);

    float x1 = std::stof(match[1]);
    float y1 = std::stof(match[2]);
    float x2 = std::stof(match[3]);
    float y2 = std::stof(match[4]);

    std::vector<std::pair<float, float> > points;
    points.emplace_back(x1, y1);
    points.emplace_back(x2, y2);
    auto rectangle = CRectangle(points);

    return rectangle;
}



