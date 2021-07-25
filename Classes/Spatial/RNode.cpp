#include "RNode.h"
#define RNODE_TEMPLATE template<typename Rectangle, typename Point>
#define RNODE_ELEMENTS Rectangle, Point

RNODE_TEMPLATE
RNode<RNODE_ELEMENTS>::RNode(){

}

RNODE_TEMPLATE
RNode<RNODE_ELEMENTS>::RNode(bool leaf){
    this->_leaf = leaf;
}

RNODE_TEMPLATE
bool RNode<RNODE_ELEMENTS>::isLeaf(){
    return this->_leaf;
}

RNODE_TEMPLATE
void RNode<RNODE_ELEMENTS>::add(Rectangle rectangle){
    this->rectangles.push_back(rectangle);
    //missing update mbr of rnode
}

RNODE_TEMPLATE
std::size_t RNode<RNODE_ELEMENTS>::size(){ 
    return rectangles.size(); 
}