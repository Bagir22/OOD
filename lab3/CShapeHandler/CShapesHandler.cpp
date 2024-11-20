#include "CShapesHandler.h"
#include "regex"
#include <utility>
#include "SFML/Graphics.hpp"
#include "../CTriangle/CTriangle.h"
#include "../CCircle/CCircle.h"
#include "../CFileDecorator/CFileDecorator.h"
#include "../CDrawDecorator/CDrawDecorator.h"
#include "../CRectangle/CRectangleCreator.h"
#include "../CTriangle/CTriangleCreator.h"
#include "../CCircle/CCircleCreator.h"

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

    while (std::getline(this->m_in, line))
    {
        if (line.find(circleStr) != std::string::npos)
        {
            auto circle = GetCircle(line);
            if (circle)
            {
                m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(circle)));
            }
        }
        else if (line.find(rectangleStr) != std::string::npos)
        {
            auto rectangle = GetRectangle(line);
            if (rectangle)
            {
                m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(rectangle)));
            }
        }
        else if (line.find(triangleStr) != std::string::npos)
        {
            auto triangle = GetTriangle(line);
            if (triangle)
            {
                m_shapes.push_back(std::make_shared<CFileDecorator>(std::make_shared<CDrawDecorator>(triangle)));
            }
        }
    }
}

void CShapesHandler::Write()
{
    for (const auto& shape : m_shapes)
    {
        shape->WriteToFile(m_out);
    }
}

void CShapesHandler::Draw()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), windowTitle);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(windowBackgroundColor));

        for (const auto& shape : m_shapes)
        {
            shape->Draw(window);
        }

        window.display();
    }
}

std::shared_ptr<CBaseShape> CShapesHandler::GetCircle(std::string line)
{
    std::regex circlePattern(parseCircle);
    std::smatch match;

    if (std::regex_search(line, match, circlePattern))
    {
        float x = std::stof(match[1]);
        float y = std::stof(match[2]);
        float radius = std::stof(match[3]);

        return CCircleCreator::GetInstance().CreateShape(radius, x, y);
    }
    return nullptr;
}

std::shared_ptr<CBaseShape> CShapesHandler::GetRectangle(std::string line)
{
    std::regex rectanglePattern(parseRectangle);
    std::smatch match;

    if (std::regex_search(line, match, rectanglePattern))
    {
        float x1 = std::stof(match[1]);
        float y1 = std::stof(match[2]);
        float x2 = std::stof(match[3]);
        float y2 = std::stof(match[4]);

        std::vector<std::pair<float, float> > points;
        points.push_back( std::pair<float, float>(x1, y1) );
        points.push_back( std::pair<float, float>(x2, y2) );
        return CRectangleCreator::GetInstance().CreateShape(points);
    }
    return nullptr;
}

std::shared_ptr<CBaseShape> CShapesHandler::GetTriangle(std::string line)
{
    std::regex trianglePattern(parseTriangle);
    std::smatch match;

    if (std::regex_search(line, match, trianglePattern))
    {
        float x1 = std::stof(match[1]);
        float y1 = std::stof(match[2]);
        float x2 = std::stof(match[3]);
        float y2 = std::stof(match[4]);
        float x3 = std::stof(match[5]);
        float y3 = std::stof(match[6]);

        return CTriangleCreator::GetInstance().CreateShape(
                sf::Vector2f(x1, y1),
                sf::Vector2f(x2, y2),
                sf::Vector2f(x3, y3));
    }
    return nullptr;
}
