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

    std::shared_ptr<CBaseShape> GetCircle(std::string line);
    std::shared_ptr<CBaseShape> GetRectangle(std::string line);
    std::shared_ptr<CBaseShape> GetTriangle(std::string line);

    std::istream& m_in;
    std::ostream& m_out;

    std::vector<std::shared_ptr<CBaseShape> >& m_shapes;
};
