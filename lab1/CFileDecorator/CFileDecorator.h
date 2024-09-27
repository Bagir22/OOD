#include "../CShapeDecorator/CShapeDecorator.h"
#include "../CBaseShape/CBaseShape.h"
#include <memory>

#ifndef LAB1_CWRITEDECORATOR_H
#define LAB1_CWRITEDECORATOR_H


class CFileDecorator : public CShapeDecorator
{
public:
    CFileDecorator(std::shared_ptr<CBaseShape> shape) : CShapeDecorator(shape) {}

    void WriteToFile(std::ostream& outFile) const override;
};

#endif
