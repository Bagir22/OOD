#include "iostream"
#include "SFML/Graphics.hpp"
#include "../CBaseShape/CBaseShape.h"
#include "../CTriangle/CTriangle.h"
#include "../CCircle/CCircle.h"
#include "../CRectangle/CRectangle.h"

class CShapesHandler
        {
public:
    CShapesHandler(std::istream& in, std::ostream& out, std::vector<std::shared_ptr<CBaseShape> >& shapes);

    void Execute();
private:
    void Write();
    void Draw();

    void GetShapes();

    CCircle GetCircle(std::string line);
    CRectangle GetRectangle(std::string line);
    CTriangle GetTriangle(std::string line);

    std::istream& m_in;
    std::ostream& m_out;

    std::vector<std::shared_ptr<CBaseShape> >& m_shapes;
};
