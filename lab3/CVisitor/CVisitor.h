#ifndef LAB2_CVISITOR_H
#define LAB2_CVISITOR_H

class CRectangle;
class CCircle;
class CTriangle;

class CVisitor {
public:
    virtual void Visit(const CRectangle& rectangle) = 0;
    virtual void Visit(const CCircle& circle) = 0;
    virtual void Visit(const CTriangle& triangle) = 0;

    virtual ~CVisitor() = default;
};

#endif //LAB2_CVISITOR_H
