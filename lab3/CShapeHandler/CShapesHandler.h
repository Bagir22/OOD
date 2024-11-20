#include "iostream"
#include "SFML/Graphics.hpp"
#include "../CBaseShape/CBaseShape.h"
#include "../CTriangle/CTriangle.h"
#include "../CCircle/CCircle.h"
#include "../CRectangle/CRectangle.h"

const int windowWidth = 1000;
const int windowHeight = 1000;
const std::string windowTitle = "Shapes";
const int windowBackgroundColor = 14737632;

const std::string parseCircle = "C=(\\d+),(\\d+);\\s+R=(\\d+)";

const std::string parseRectangle = "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+)";

const std::string parseTriangle= "P1=(\\d+),(\\d+);\\s+P2=(\\d+),(\\d+);\\s+P3=(\\d+),(\\d+)";

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
