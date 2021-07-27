#include "RTree.h"
#define RTREE_TEMPLATE template<typename Point, typename DataType, std::size_t MAXNODES, std::size_t MINNODES> 
#define RTREE_DEFINITION RTree<Point, DataType, MAXNODES, MINNODES>


RTREE_TEMPLATE
bool RTREE_DEFINITION::checkRNode(std::shared_ptr<node_t> node){
    if(node.size() <= this->_MAXNODES) return true;
    return false;
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insertUtil(std::shared_ptr<node_t> node, rectangle_t rectangle, DataType data){
    if(!node){
        node = std::make_shared<node_t>(true);
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
    rectangle_t rect(point, point);
    insertUtil(this->_root, rect, data);
    if(!this->checkRNode(_root)){
        
    }
}

RTREE_TEMPLATE
bool RTREE_DEFINITION::overlap(rectangle_t rectA, rectangle_t rectB){
    std::size_t dimension = rectA.getDimension();
    for(int index = 0; index < dimension; ++index){
        if (rectA._min.get(index) > rectB._max.get(index) ||
            rectB._min.get(index) > rectA._max.get(index))
        return false;
    }
  return true;
}

RTREE_TEMPLATE
std::pair<RNode<Point, DataType>, RNode<Point, DataType>> RTREE_DEFINITION::splitNode(node_t node){

}