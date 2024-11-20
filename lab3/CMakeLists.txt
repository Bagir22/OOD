cmake_minimum_required(VERSION 3.27)
project(lab2)

find_package(SFML 2.5 COMPONENTS window graphics system REQUIRED)

add_executable(lab2 main.cpp
        CBaseShape/CBaseShape.h
        CDrawDecorator/CDrawDecorator.cpp
        CShapeDecorator/CShapeDecorator.cpp
        CShapeHandler/CShapesHandler.cpp
        CTriangle/CTriangle.cpp
        CFileDecorator/CFileDecorator.cpp
        CCircle/CCircle.h
        CCircle/CCircle.cpp
        CRectangle/CRectangle.h
        CRectangle/CRectangle.cpp
        CRectangle/CRectangleCreator.h
        CCircle/CCircleCreator.h
        CTriangle/CTriangleCreator.h
        CVisitor/CVisitor.h
        CPrinter/CPrinter.h
        CPrinter/CPrinter.cpp
)
target_link_libraries(lab2 sfml-graphics sfml-audio)