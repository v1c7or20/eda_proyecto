#include <iostream>
#include "parser/barrios_parser.h"
#include "tests/tests.cpp"

int main(int argc, char **argv) {
    barrios_parser parser1("./../neighboord.json");
    std::cout << "Hello, World!" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
