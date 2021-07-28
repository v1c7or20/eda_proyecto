#ifndef EDA_PROYECTO_RTREE_H
#define EDA_PROYECTO_RTREE_H

#include <memory>
#include <cassert>
#include "RNode.h"

template<typename Point, typename DataType, std::size_t MAXNODES = 4, std::size_t MINNODES = MAXNODES / 2>
class RTree{
private:
    using rectangle_t = Rectangle<Point>; 
    using node_t = RNode<Point, DataType>;
    using entry_t = Entry<node_t, Point, DataType>;
    void insertRectangle(rectangle_t& rectangle, DataType& data);
    void insertUtil(std::shared_ptr<node_t> node, rectangle_t& rectangle, DataType& data);
    std::vector<DataType> searchRectangle(rectangle_t& rectangle);
    std::vector<DataType> searchUtil(std::shared_ptr<node_t> node, rectangle_t& rectangle);
    bool checkRNode(std::shared_ptr<node_t> node);
    std::pair<std::shared_ptr<node_t>, std::shared_ptr<node_t>> splitNode(std::shared_ptr<node_t> node);
    std::pair<std::shared_ptr<node_t>, std::shared_ptr<node_t>> quadraticSplit(std::shared_ptr<node_t> node);
    std::vector<std::shared_ptr<node_t>> qPickSeeds(std::shared_ptr<node_t> node);
    void qDistribute(std::shared_ptr<node_t> nodeToSplit, std::shared_ptr<node_t> nodeA, std::shared_ptr<node_t> nodeB);
    std::shared_ptr<entry_t> pickNext(std::shared_ptr<node_t> nodeToSplit, std::shared_ptr<node_t> nodeA, std::shared_ptr<node_t> nodeB);
public:
    RTree(){ assert(MAXNODES >= 2 && MAXNODES > MINNODES); } 
    void insert(Point point, DataType data);
    void insert(Point min, Point max, DataType data);
    void insert(rectangle_t rectangle, DataType data);
    std::vector<DataType> search(Point point);
    std::vector<DataType> search(Point min, Point max);
    std::vector<DataType> search(rectangle_t rectangle);
private:
    std::shared_ptr<node_t> _root;
};


#endif // EDA_PROYECTO_RTREE_H