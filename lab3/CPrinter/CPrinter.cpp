#include "CPrinter.h"

void CPrinter::Visit(const CRectangle& rectangle) {
    m_out << rectangleStr << perimeterStr << rectangle.GetPerimeter() << squareStr << rectangle.GetArea() << "\n";
}

void CPrinter::Visit(const CCircle& circle) {
    m_out << circleStr <<  perimeterStr << circle.GetPerimeter() << squareStr << circle.GetArea() << "\n";
}

void CPrinter::Visit(const CTriangle& triangle) {
    m_out << triangleStr << perimeterStr << triangle.GetPerimeter() << squareStr << triangle.GetArea() << "\n";
}