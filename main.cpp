#include <iostream>
#include "Parser/NeighborhoodParser.h"
#include "Parser/PointParser.h"
#include "Parser/BarriosParser.h"
#include "Tests/Tests.cpp"

int main(int argc, char **argv) {
    // NeighborhoodParser parser1("./../neighboord.json");
    // PointParser parser2("./../green_tripdata_2015-01.csv");
    bool pleaseTrue = parser2.getPoints().at(1)->isInsidePolygon(
            std::vector<std::pair<double,double>> {{-10000,-10000}, {10000, -10000}, {10000,10000}, {-10000,10000}});
    std::cout << "Hello, World!" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
