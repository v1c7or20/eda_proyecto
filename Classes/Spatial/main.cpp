#include <variant>
#include <iostream>
#include "RTree.cpp"
#include "Point.h"
#include "Rectangle.h"
#include "RNode.cpp"
using point_t = Point<int, 2>;
using rectangle_t = Rectangle<point_t>;
using rnode_t = RNode<rectangle_t, point_t, int>;
using namespace std;
int main(){
    //RTree<RNode<point_t, rectangle_t>, rectangle_t, point_t> rtree;
    rectangle_t rectA(point_t({3, 2}), point_t({5, 6}));
    /*rectangle_t rectB(point_t({4, 3}), point_t({10, 4}));
    rectangle_t result = rnode_t::rectangleIncluding(rectA, rectB);
    cout << result._min.get(0) << "," << result._min.get(1) << endl;
    cout << result._max.get(0) << "," << result._max.get(1) << endl;*/
    /*std::shared_ptr<int> a = std::make_shared<int>(2);
    if(a == nullptr)
        cout << "si es null" << endl;
    else cout << "no es null" << endl;*/
    rnode_t rtree;
    rtree.createBranch(rectA, 10);

}