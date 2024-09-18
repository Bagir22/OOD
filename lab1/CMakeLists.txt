cmake_minimum_required(VERSION 3.27)
project(lab1)

find_package(SFML 2.5 COMPONENTS window graphics system REQUIRED)

add_executable(lab1 main.cpp
        CShapeHandler/CShapesHandler.h
        CShapeDecorator/CShapeDecorator.h
        CCircleDecorator/CCircleDecorator.h
        CCircleDecorator/CCircleDecorator.cpp
        CShapeHandler/CShapesHandler.cpp
        CShapeDecorator/CShapeDecorator.cpp
)
target_link_libraries(lab1 sfml-graphics sfml-audio)