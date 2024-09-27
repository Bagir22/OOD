#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "CShapeHandler/CShapesHandler.h"
#include "CBaseShape/CBaseShape.h"
#include "CTriangle/CTriangle.h"
#include "CDrawDecorator/CDrawDecorator.h"
#include "CFileDecorator/CFileDecorator.h"

const std::string inFileErr = "Input file doesn't exist\n";

int main()
{
    std::ifstream in("input.txt");
    if (in.fail())
    {
        std::cout << inFileErr;
        return 1;
    }
    std::ofstream out("output.txt");

    std::vector<std::shared_ptr<CBaseShape> > shapes;

    CShapesHandler handler = CShapesHandler(in, out, shapes);

    handler.Execute();

    return 0;
}