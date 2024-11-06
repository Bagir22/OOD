#include "../CBaseShape/CBaseShape.h"
#include "../CRectangle/CRectangle.h"

#ifndef LAB1_CREACTANGLECREATOR_H
#define LAB1_CREACTANGLECREATOR_H

class CRectangleCreator
{
public:
    static CRectangleCreator& GetInstance()
    {
        static CRectangleCreator instance;
        return instance;
    }

    static std::shared_ptr<CBaseShape> CreateShape(const std::vector<std::pair<float, float> >& points) {
        return std::make_shared<CRectangle>(points);
    }

private:
    CRectangleCreator() {}
    CRectangleCreator(const CRectangleCreator&) = delete;
    CRectangleCreator& operator=(const CRectangleCreator&) = delete;
};

#endif
