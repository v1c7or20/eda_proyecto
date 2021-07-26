#include "RNode.h"
#define RNODE_TEMPLATE template<typename Rectangle, typename Point, typename DataType>
#define RNODE_DEFINITION RNode<Rectangle, Point, DataType>

RNODE_TEMPLATE
RNode<Rectangle, Point, DataType>::RNode(bool leaf){
    assert(leaf);
    this->_leaf = leaf;
}

RNODE_TEMPLATE
bool RNODE_DEFINITION::isLeaf(){
    return this->_leaf;
}

RNODE_TEMPLATE
std::shared_ptr<RNODE_DEFINITION> RNODE_DEFINITION::pickChild(Rectangle rectangle){
    bool firstTime = true;
    double bestArea;
    double bestIncrease;
    std::size_t bestRectIndex;
    for(std::size_t i = 0; i < this->_branches.size(); i++){
        Rectangle currentRect = this->_branches[i].rectangle;
        Rectangle tempRect = RNODE_DEFINITION::rectangleIncluding(currentRect, rectangle);
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
    return std::get<RNODE_POINTER>(this->_branches[bestRectIndex].element);
}

RNODE_TEMPLATE
void RNODE_DEFINITION::add(Rectangle rectangle, DataType data){
    Branch branch(rectangle, data);
    this->_branches.push_back(branch);
}

RNODE_TEMPLATE
std::size_t RNODE_DEFINITION::size(){ 
    return _branches.size(); 
}

RNODE_TEMPLATE
Rectangle RNODE_DEFINITION::rectangleIncluding(Rectangle rectA, Rectangle rectB){
    const int x = 0, y = 1;
    Point min({std::min(rectA._min.get(x), rectB._min.get(x)),
                   std::min(rectA._min.get(y), rectB._min.get(y))});
    Point max({std::max(rectA._max.get(x), rectB._max.get(x)),
                   std::max(rectA._max.get(y), rectB._max.get(y))});
    return Rectangle(min, max);
}

RNODE_TEMPLATE
void RNODE_DEFINITION::createBranch(Rectangle rectangle, DataType data){
    Branch branch(rectangle, data);
    this->_branches.push_back(branch);
    std::cout << _branches[0].rectangle._min.get(0) << "," << _branches[0].rectangle._min.get(1) << std::endl;
    std::cout << std::get<DataType>(_branches[0].element) << std::endl;
}