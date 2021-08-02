#include "Classes/Parser/NeighborhoodParser.h"
#include "Classes/Parser/TravelParser.h"
#include "Tests/Tests.cpp"

using point_t = Point<double, 2>;

int main(int argc, char **argv) {
    NeighborhoodParser parser1("./../neighboord.json");
    TravelParser parser2("./../green_tripdata_2015-01.csv");
    bool pleaseTrue = parser2.getTravels().at(1)->getStartingPoint().isInsidePolygon(
            std::vector<point_t> {point_t({-10000,-10000}), point_t({10000, -10000}), point_t({10000,10000}), point_t({-10000,10000})});
    if(pleaseTrue){
        std::cout << "Hello, World!" << std::endl;
    }else{
        std::cout << "no Hello, World!" << std::endl;
    }
    Travel t2 = *parser2.getTravels().at(1);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
