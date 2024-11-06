#include <memory>
#include "../CTriangle/CTriangle.h"

#ifndef LAB2_CTRIANGLECREATOR_H
#define LAB2_CTRIANGLECREATOR_H

class CTriangleCreator
{
public:
    static CTriangleCreator& GetInstance()
    {
        static CTriangleCreator instance;
        return instance;
    }

    static std::shared_ptr<CBaseShape> CreateShape(sf::Vector2f firstPoint, sf::Vector2f secondPoint, sf::Vector2f thirdPoint) {
        return std::make_shared<CTriangle>(firstPoint, secondPoint, thirdPoint);
    }

private:
    CTriangleCreator() { }
    CTriangleCreator(const CTriangleCreator&) = delete;
    CTriangleCreator& operator=(const CTriangleCreator&) = delete;
};

#endif
