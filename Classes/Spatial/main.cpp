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
    point_t P1({1, 1}), P2({2, 11}), P3({6, 10}), P4({1, 9}), P5({1, 13}),
            P6({2, 9}), P7({8, 1}), P8({4, 8}), P9({2, 4}), P10({4, 10}),
            P11({6, 3}), P12({6, 1}), P13({2, 2}), P14({7, 5}), P15({7, 2});
    // rectangle_t R1(point_t({1, 8}), point_t({4, 9}));
    // rectangle_t R2(point_t({1, 10}), point_t({6, 13}));
    // rectangle_t R3(point_t({1, 1}), point_t({2, 4}));
    // rectangle_t R4(point_t({6, 1}), point_t({8, 3}));
    // rectangle_t R5(point_t({7, 2}), point_t({7, 5}));
    // rtree.insert(R1, 1);
    // rtree.insert(R2, 2);
    // rtree.insert(R3, 3);
    // rtree.insert(R4, 4);
    // rtree.insert(R5, 5);
    rtree.insert(P1, 1);
    rtree.insert(P2, 2);
    rtree.insert(P3, 3);
    rtree.insert(P4, 4);
    rtree.insert(P5, 5);
    rtree.insert(P6, 6);
    rtree.insert(P7, 7);
    rtree.insert(P8, 8);
    rtree.insert(P9, 9);
    rtree.insert(P10, 10);
    rtree.insert(P11, 11);
    rtree.insert(P12, 12);
    rtree.insert(P13, 13);
    rtree.insert(P14, 14);
    rtree.insert(P15, 15);
}