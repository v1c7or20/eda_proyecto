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

    void insertUtil(std::shared_ptr<node_t> node, rectangle_t rectangle, DataType data);
    bool checkRNode(std::shared_ptr<node_t> node);
    std::pair<node_t, node_t> splitNode(node_t node);
public:
    RTree()= default;
    void insert(Point new_point, DataType data);
    bool overlap(rectangle_t rect1, rectangle_t rect2);
private:
    std::shared_ptr<node_t> _root;
};


#endif // EDA_PROYECTO_RTREE_H