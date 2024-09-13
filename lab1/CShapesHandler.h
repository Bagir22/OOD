#include "iostream"

#include "CShapeDecorator.h"

class CShapesHandler {
    CShapesHandler( std::istream& in, std::ostream& out, std::vector<std::shared_ptr<CShapeDecorator> >& shapes);
};
