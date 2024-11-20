#include "CFileDecorator.h"
#include "iostream"
#include "../CPrinter/CPrinter.h"

void CFileDecorator::WriteToFile(std::ostream &outFile) const
{
    CPrinter visitor(outFile);
    shape->Accept(visitor);
}

