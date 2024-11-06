#include "CFileDecorator.h"
#include "iostream"
#include <iomanip>

const int precision = 2;

void CFileDecorator::WriteToFile(std::ostream &outFile) const
{
    outFile << std::fixed << std::setprecision(precision);
    CShapeDecorator::WriteToFile(outFile);
    outFile << "P=" << GetPerimeter() << "; S=" << GetArea() << "\n";
}

