#include "RTree.h"
#define RTREE_TEMPLATE template<typename Node, typename Rectangle, typename Point> 
#define RTREE_ELEMENTS Node, Rectangle, Point

RTREE_TEMPLATE
RTree<RTREE_ELEMENTS>::RTree(){
    this->_MAXNODES = 4; 
    this->_MINNODES = this->_MAXNODES / 2;
}

RTREE_TEMPLATE
RTree<RTREE_ELEMENTS>::RTree(std::size_t MAXNODES, std::size_t MINNODES){
    assert(MAXNODES > MINNODES);
    this->_MAXNODES = MAXNODES;
    this->_MINNODES = MINNODES;
}

RTREE_TEMPLATE
bool RTree<RTREE_ELEMENTS>::checkRNode(std::shared_ptr<Node> node){
    if(node.size() <= this->_MAXNODES) return true;
    return false;
}

RTREE_TEMPLATE
void RTree<RTREE_ELEMENTS>::insertUtil(std::shared_ptr<Node> node, Rectangle rectangle){
    if(!node){
        node = std::make_shared<Node>(true);
    }

    if(node.isLeaf()){
        node.add(rectangle);
    }

    if(!checkRNode(node)){

    }
    //function incompleted
}

RTREE_TEMPLATE
void RTree<RTREE_ELEMENTS>::insert(Point point){
    Rectangle rect(point, point);
    insertUtil(this->_root, rect);
}

RTREE_TEMPLATE
bool RTree<RTREE_ELEMENTS>::overlap(Rectangle rectA, Rectangle rectB){
    std::size_t dimension = rectA.getDimension();
    for(int index = 0; index < dimension; ++index){
        if (rectA._min.get(index) > rectB._max.get(index) ||
            rectB._min.get(index) > rectA._max.get(index))
        return false;
    }
  return true;
}