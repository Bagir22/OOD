#include <memory>
#include <vector>
#include "../CCircle/CCircle.h"

#ifndef LAB3_CCIRCLECREATOR_H
#define LAB3_CCIRCLECREATOR_H

class CCircleCreator
{
public:
    static CCircleCreator& GetInstance()
    {
        static CCircleCreator instance;
        return instance;
    }

    static std::shared_ptr<CBaseShape> CreateShape(float radius, float x, float y) {
        return std::make_shared<CCircle>(radius, x, y);
    }

private:
    CCircleCreator() {}
    CCircleCreator& operator=(const CCircleCreator&) = delete;
    CCircleCreator(const CCircleCreator&) = delete;
};

#endif
