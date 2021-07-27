#include "RNode.h"
#define RNODE_TEMPLATE template<typename Point, typename DataType>
#define RNODE_DEFINITION RNode<Point, DataType>

RNODE_TEMPLATE
RNode<Point, DataType>::RNode(bool leaf){
    assert(leaf);
    this->_leaf = leaf;
}

RNODE_TEMPLATE
bool RNODE_DEFINITION::isLeaf(){
    return this->_leaf;
}

RNODE_TEMPLATE
std::shared_ptr<RNODE_DEFINITION> RNODE_DEFINITION::pickChild(rectangle_t rectangle){
    bool firstTime = true;
    double bestArea;
    double bestIncrease;
    std::size_t bestRectIndex;
    for(std::size_t i = 0; i < this->_branches.size(); i++){
        rectangle_t currentRect = this->_branches[i]->rectangle;
        rectangle_t tempRect = RNODE_DEFINITION::rectangleIncluding(currentRect, rectangle);
        double areaCurrentRect = currentRect.getArea();
        double increase = tempRect.getArea() - areaCurrentRect;
        if((increase < bestIncrease) || firstTime ||
            (increase == bestIncrease && areaCurrentRect < bestArea)){
            bestRectIndex = i;
            bestArea = areaCurrentRect;
            bestIncrease = increase;
            firstTime = false;
        }
    }
    return std::get<RNODE_POINTER>(this->_branches[bestRectIndex]->element);
}

RNODE_TEMPLATE
void RNODE_DEFINITION::add(rectangle_t rectangle, DataType data){
    auto branch = std::make_shared<Branch>(rectangle, data);
    this->_branches.push_back(branch);
}

RNODE_TEMPLATE
std::size_t RNODE_DEFINITION::size(){ 
    return _branches.size(); 
}

RNODE_TEMPLATE
Rectangle<Point> RNODE_DEFINITION::rectangleIncluding(rectangle_t rectA, rectangle_t rectB){
    const int x = 0, y = 1;
    Point min({std::min(rectA._min.get(x), rectB._min.get(x)),
                   std::min(rectA._min.get(y), rectB._min.get(y))});
    Point max({std::max(rectA._max.get(x), rectB._max.get(x)),
                   std::max(rectA._max.get(y), rectB._max.get(y))});
    return rectangle_t(min, max);
}

RNODE_TEMPLATE
void RNODE_DEFINITION::createBranch(rectangle_t rectangle, DataType data){
    auto branch = std::make_shared<Branch>(rectangle, data);
    this->_branches.push_back(branch);
    std::cout << _branches[0]->rectangle._min.get(0) << "," << _branches[0]->rectangle._min.get(1) << std::endl;
    std::cout << std::get<DataType>(_branches[0]->element) << std::endl;
}