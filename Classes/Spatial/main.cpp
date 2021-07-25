#include <iostream>
#include "RTree.cpp"
#include "Point.h"
#include "Rectangle.h"
#include "RNode.h"
using point_t = Point<int, 2>;
using rectangle_t = Rectangle<point_t>;
using std::cout; 
using std::endl;
int main(){
    //RTree<RNode<point_t, rectangle_t>, rectangle_t, point_t> rtree;
    rectangle_t rectA(point_t({-3, -3}), point_t({0, 0}));
    rectangle_t rectB(point_t({0, 0}), point_t({1, 1}));
    cout << rectA.getArea() << endl;
    cout << rectB.getArea() << endl;
}