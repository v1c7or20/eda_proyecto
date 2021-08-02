#include "Solver.h"
#include <queue>

Solver::Solver(std::vector<Travel*>& travels, std::vector<Neighborhood*>& neighborhoods){
    for(auto& neighborhood : neighborhoods){
        neighborhoodsRTree.insert(neighborhood->getMBR(), neighborhood);
        mapping[neighborhood] = 0;
    }
    for(auto& travel : travels){
        addTravel(travel);
    }
}

std::vector<Travel*> Solver::query1(){
    return this->queryResult1;
}

std::vector<Neighborhood*> Solver::query2(std::size_t k){
    std::priority_queue<std::pair<int, Neighborhood*>> pq;
    for(auto& item : mapping){
        int value = (-1) * item.second;
        if(pq.size() < k){
            pq.push({value, item.first});
        }
        else{
            if(value < pq.top().first){
                pq.pop();
                pq.push({value, item.first});
            }
        }
    }
    std::vector<Neighborhood*> result(k);
    for(std::size_t i = k - 1; i >= 0; --i){
        result[i] = pq.top().second;
        pq.pop();
    }
    return result;
    
}

std::vector<Travel*> Solver::query3(point_t p1, point_t p2){
    return travelsRTreeBySP.search(p1, p2);
}

std::vector<Travel*> Solver::query4(point_t point, double distance){
    auto result1 = travelsRTreeBySP.rangeSearch(point, distance);
    auto result2 = travelsRTreeByAP.rangeSearch(point, distance);
    result1.insert(result1.end(), result2.begin(), result2.end());
    return result1;
}

void Solver::addTravel(Travel* travel){
    auto startingPoint = travel->getStartingPoint();
    auto arrivalPoint = travel->getArrivalPoint();
    auto result = neighborhoodsRTree.search(startingPoint.getPoint());
    for(auto& neighborhood : result){
        if(startingPoint.isInsidePolygon(neighborhood->getPolygon())){
            mapping[neighborhood] += 1;
            startingPoint.setNeighborhood(neighborhood);
            break;
        }
    }

    result = neighborhoodsRTree.search(arrivalPoint.getPoint());
    for(auto& neighborhood : result){
        if(arrivalPoint.isInsidePolygon(neighborhood->getPolygon())){
            arrivalPoint.setNeighborhood(neighborhood);
            break;
        }
    }
    
    if(startingPoint.getNeighborhood()->getName() == 
        arrivalPoint.getNeighborhood()->getName()){
        queryResult1.push_back(travel);
    }

    travelsRTreeBySP.insert(startingPoint.getPoint(), travel);
    travelsRTreeByAP.insert(arrivalPoint.getPoint(), travel);
}