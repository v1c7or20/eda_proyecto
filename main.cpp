#include <iostream>
#include "Parser/BarriosParser.h"
#include "tests/tests.cpp"

int main(int argc, char **argv) {
    BarriosParser parser1("./../neighboord.json");
    std::cout << "Hello, World!" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
