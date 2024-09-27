cmake_minimum_required(VERSION 3.27)
project(lab1)

find_package(SFML 2.5 COMPONENTS window graphics system REQUIRED)

add_executable(lab1 main.cpp
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
)
target_link_libraries(lab1 sfml-graphics sfml-audio)