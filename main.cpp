#include "Parser/NeighborhoodParser.h"
#include "Parser/TravelParser.h"

int main() {
 // NeighborhoodParser parser1("./../neighboord.json");
    TravelParser parser2("./../green_tripdata_2015-01.csv");
    bool pleaseTrue = parser2.getTravels().at(1)->getStartingPoint().isInsidePolygon(
            std::vector<std::pair<double,double>> {{-10000,-10000}, {10000, -10000}, {10000,10000}, {-10000,10000}});
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
