#include <variant>
#include <iostream>
#include "RTree.cpp"
#include "Point.h"
#include "Rectangle.h"
#include "RNode.cpp"

using point_t = Point<int, 2>;
using rectangle_t = Rectangle<point_t>;
using rnode_t = RNode<point_t, int>;
using rtree_t = RTree<point_t, int, 4, 2>;
//using rtree_t = RTree<point_t, int, 8, 2>;

using namespace std;
int main(){
    rtree_t rtree;
    rectangle_t R1(point_t({1, 8}), point_t({4, 9}));
    rectangle_t R2(point_t({1, 10}), point_t({6, 13}));
    rectangle_t R3(point_t({1, 1}), point_t({2, 4}));
    rectangle_t R4(point_t({6, 1}), point_t({8, 3}));
    rectangle_t R5(point_t({7, 2}), point_t({7, 5}));
    rtree.insert(R1, 1);
    rtree.insert(R2, 2);
    rtree.insert(R3, 3);
    rtree.insert(R4, 4);
    rtree.insert(R5, 5);
}