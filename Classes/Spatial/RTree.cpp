#include "RTree.h"
#define RTREE_TEMPLATE template<typename Node, typename Rectangle, typename Point, typename DataType> 
#define RTREE_DEFINITION RTree<Node, Rectangle, Point, DataType>

RTREE_TEMPLATE
RTree<Node, Rectangle, Point, DataType>::RTree(){
    _MAXNODES = 4;
    _MINNODES = _MAXNODES / 2;
}

RTREE_TEMPLATE
RTree<Node, Rectangle, Point, DataType>::RTree(std::size_t MAXNODES, std::size_t MINNODES){
    assert(MAXNODES > MINNODES);
    _MAXNODES = MAXNODES;
    _MINNODES = MINNODES;
}

RTREE_TEMPLATE
bool RTREE_DEFINITION::checkRNode(std::shared_ptr<Node> node){
    if(node.size() <= this->_MAXNODES) return true;
    return false;
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insertUtil(std::shared_ptr<Node> node, Rectangle rectangle, DataType data){
    if(!node){
        node = std::make_shared<Node>(true);
    }

    if(node.isLeaf()){
        node.add(rectangle, data);
        return;
    }

    auto nextChild = node->pickChild(rectangle);
    insertUtil(nextChild, rectangle, data);
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insert(Point point, DataType data){
    Rectangle rect(point, point);
    insertUtil(this->_root, rect, data);
    if(!this->checkRNode(_root)){
        
    }
}

RTREE_TEMPLATE
bool RTREE_DEFINITION::overlap(Rectangle rectA, Rectangle rectB){
    std::size_t dimension = rectA.getDimension();
    for(int index = 0; index < dimension; ++index){
        if (rectA._min.get(index) > rectB._max.get(index) ||
            rectB._min.get(index) > rectA._max.get(index))
        return false;
    }
  return true;
}