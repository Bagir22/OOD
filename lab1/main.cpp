#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

#include "CShapeDecorator.h"

const std::string inFileErr = "Input file doesn't exist\n";

int main() {

    std::ifstream in("input.txt");
    if (in.fail()) {
        std::cout << inFileErr;
        return 1;
    }
    std::ofstream out("output.txt");


    std::vector<std::shared_ptr<CShapeDecorator> > shapes;

    return 0;
}