#include "../CVisitor/CVisitor.h"
#include "iostream"
#include "../CRectangle/CRectangle.h"
#include "../CCircle/CCircle.h"
#include "../CTriangle/CTriangleCreator.h"

#ifndef LAB2_CPRINTER_H
#define LAB2_CPRINTER_H

const std::string perimeterStr = "P=";
const std::string squareStr = "; S=" ;

class CPrinter : public CVisitor {
public:
    explicit CPrinter(std::ostream& out) : m_out(out) {}

    void Visit(const CRectangle& rectangle) override;
    void Visit(const CCircle& circle) override;
    void Visit(const CTriangle& triangle) override;

private:
    std::ostream& m_out;
};

#endif // C_PRINTER_H

