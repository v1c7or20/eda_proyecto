#ifndef EDA_PROYECTO_SOLVER_H
#define EDA_PROYECTO_SOLVER_H

#include "../Spatial/RTree.h"
#include "../Spatial/Point.h"
#include "../Basic/Travel.h"
#include "../Basic/Neighborhood.h"

#include <unordered_map>

class Solver{
private:
    using point_t = Point<double, 2>;
    void addTravelVector(std::vector<Travel*>::iterator start, std::vector<Travel*>::iterator finish);
public:
    Solver(std::vector<Travel*> &travels, std::vector<Neighborhood*> &neighborhoods);
    std::vector<Travel*> query1();
    std::vector<Neighborhood*> query2(std::size_t k);
    std::vector<Travel*> query3(point_t p1, point_t p2);
    std::vector<Travel*> query4(point_t point, double distance);
    void addTravel(Travel* travel);
    std::unordered_map<Neighborhood*, std::size_t> getMapping();
private:
    RTree<point_t, Neighborhood*, 4, 2> neighborhoodsRTree;
    RTree<point_t, Travel*, 4, 2> travelsRTreeBySP;
    RTree<point_t, Travel*, 4, 2> travelsRTreeByAP;
    std::vector<Travel*> queryResult1;
    std::unordered_map<Neighborhood*, std::size_t> mapping;
};

#endif // EDA_PROYECTO_SOLVER_H
