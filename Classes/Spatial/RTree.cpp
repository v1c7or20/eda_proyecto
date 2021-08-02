#include "RTree.h"
#include "RNode.h"

RTREE_TEMPLATE
std::shared_ptr<RNode<Point, DataType>> RTREE_DEFINITION::getRoot(){
  return this->_root;
}

RTREE_TEMPLATE
bool RTREE_DEFINITION::checkRNode(std::shared_ptr<node_t> node){
    return node->size() <= MAXNODES;
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insertRectangle(rectangle_t& rectangle, DataType& data){
    if(!_root){
        _root = std::make_shared<node_t>(true);
    }
    insertUtil(this->_root, rectangle, data);

    if(!this->checkRNode(_root)){
        auto result = splitNode(_root);
        assert(_root->size() == 0);
        auto nodeA = result.first;
        auto nodeB = result.second;
        _root.reset();
        _root = std::make_shared<node_t>(false);
        _root->add(std::make_shared<entry_t>(nodeA->getNodeMBR(), nodeA));
        _root->add(std::make_shared<entry_t>(nodeB->getNodeMBR(), nodeB));
    }
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insertUtil(std::shared_ptr<node_t> node, rectangle_t& rectangle, DataType& data){
    if(node->isLeaf()){
        node->add(std::make_shared<entry_t>(rectangle, data));
        return;
    }

    std::size_t indexNextChild = node->pickChild(rectangle);
    auto nextEntry = node->getEntry(indexNextChild);
    auto nextChild = nextEntry->getChild();
    std::size_t prevSize = nextChild->size();
    insertUtil(nextChild, rectangle, data);
    if(!checkRNode(nextChild)){
        auto result = splitNode(nextChild);
        auto nodeA = result.first;
        auto nodeB = result.second;
        node->setNewEntry(indexNextChild, std::make_shared<entry_t>(nodeA->getNodeMBR(), nodeA));
        node->add(std::make_shared<entry_t>(nodeB->getNodeMBR(), nodeB));
    }else if(nextChild->isLeaf()){
        nextEntry->rectangle = rectangle_t::rectangleIncluding(nextEntry->rectangle, rectangle);
    }else if(prevSize != nextChild->size()){
        nextEntry->rectangle = nextChild->getNodeMBR();
    }
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insert(Point point, DataType data){
    rectangle_t rectangle(point, point);
    insertRectangle(rectangle, data);
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insert(Point min, Point max, DataType data){
    rectangle_t rectangle(min, max);
    insertRectangle(rectangle, data);
}

RTREE_TEMPLATE
void RTREE_DEFINITION::insert(rectangle_t rectangle, DataType data){
    insertRectangle(rectangle, data);
}

RTREE_TEMPLATE
std::pair<std::shared_ptr<RNODE_DEFINITION>, std::shared_ptr<RNODE_DEFINITION>> RTREE_DEFINITION::splitNode(std::shared_ptr<node_t> node){
    assert(node->size() > MAXNODES);
    return quadraticSplit(node);
}

RTREE_TEMPLATE
std::pair<std::shared_ptr<RNODE_DEFINITION>, std::shared_ptr<RNODE_DEFINITION>> RTREE_DEFINITION::quadraticSplit(std::shared_ptr<node_t> node){
    auto result = qPickSeeds(node);
    auto nodeToSplit = result[0];
    auto nodeA = result[1];
    auto nodeB = result[2];
    qDistribute(nodeToSplit, nodeA, nodeB);
    return {nodeA, nodeB};
}

RTREE_TEMPLATE
std::vector<std::shared_ptr<RNODE_DEFINITION>> RTREE_DEFINITION::qPickSeeds(std::shared_ptr<node_t> node){
    assert(node->size() == MAXNODES + 1);
    std::size_t entryIndexA, entryIndexB;
    double maxArea = -1;
    for(std::size_t i = 0; i < MAXNODES; ++i){
        for(std::size_t j = i + 1; j < MAXNODES + 1; ++j){
            rectangle_t rectA = node->getEntry(i)->rectangle;
            rectangle_t rectB = node->getEntry(j)->rectangle;
            rectangle_t r = rectangle_t::rectangleIncluding(rectA, rectB);
            double area = r.getRegion(false) - rectA.getRegion(false) - rectB.getRegion(false);
            if(area > maxArea){
                maxArea = area;
                entryIndexA = i;
                entryIndexB = j;
            }
        }
    }
    assert(entryIndexA < entryIndexB);
    auto nodeA = std::make_shared<node_t>(node->isLeaf());
    auto nodeB = std::make_shared<node_t>(node->isLeaf());
    nodeA->add(node->getEntry(entryIndexA));
    nodeB->add(node->getEntry(entryIndexB));
    node->popEntry(entryIndexA);
    node->popEntry(entryIndexB - 1);
    return {node, nodeA, nodeB};
}

RTREE_TEMPLATE
void RTREE_DEFINITION::qDistribute(std::shared_ptr<node_t> nodeToSplit, std::shared_ptr<node_t> nodeA, std::shared_ptr<node_t> nodeB){
    while(!(nodeToSplit->size() == 0 || nodeA->size() == MAXNODES - MINNODES + 1 
                                     || nodeB->size() == MAXNODES - MINNODES + 1)){
        auto entry = pickNext(nodeToSplit, nodeA, nodeB);
        rectangle_t mbrA = nodeA->getNodeMBR();
        rectangle_t mbrB = nodeB->getNodeMBR();
        double areaA = rectangle_t::areaIncrease(mbrA, entry->rectangle);
        double areaB = rectangle_t::areaIncrease(mbrB, entry->rectangle);
        if(areaA < areaB){
            nodeA->add(entry);
        }else if(areaB < areaA){
            nodeB->add(entry);
        }else if(mbrA.getRegion(false) < mbrB.getRegion(false)){
            nodeA->add(entry);
        }else if(mbrB.getRegion(false) < mbrA.getRegion(false)){
            nodeB->add(entry);
        }else if(nodeA->size() < nodeB->size()){
            nodeA->add(entry);
        }else{
            nodeB->add(entry);
        }
    }
    if(nodeA->size() == MAXNODES - MINNODES + 1){
        for(std::size_t i = 0; i < nodeToSplit->size(); ++i){
            nodeB->add(nodeToSplit->getEntry(i));
        }
    }else{
        for(std::size_t i = 0; i < nodeToSplit->size(); ++i){
            nodeA->add(nodeToSplit->getEntry(i));
        }
    }
    nodeToSplit->clearEntries();
}

RTREE_TEMPLATE
std::shared_ptr<ENTRY_DEFINITION> RTREE_DEFINITION::pickNext(std::shared_ptr<node_t> nodeToSplit, std::shared_ptr<node_t> nodeA, std::shared_ptr<node_t> nodeB){
    double maxArea = -1;
    std::size_t indexEntry;
    for(std::size_t i = 0; i < nodeToSplit->size(); ++i){
        double areaA = rectangle_t::areaIncrease(nodeA->getNodeMBR(), nodeToSplit->getEntry(i)->rectangle);
        double areaB = rectangle_t::areaIncrease(nodeB->getNodeMBR(), nodeToSplit->getEntry(i)->rectangle);
        double diff = std::abs(areaA - areaB);
        if(diff > maxArea){
            maxArea = diff;
            indexEntry = i;
        }
    }
    auto entry = nodeToSplit->getEntry(indexEntry);
    nodeToSplit->popEntry(indexEntry);
    return entry;
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::searchRectangle(rectangle_t& rectangle){
    if(!_root){
        return std::vector<DataType>();
    }
    return searchUtil(_root, rectangle);
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::searchUtil(std::shared_ptr<node_t> node, rectangle_t& rectangle){
    if(node->isLeaf()){
        return node->getAllData(rectangle);
    }
    std::vector<DataType> result;
    for(std::size_t i = 0; i < node->size(); i++){
        if(rectangle_t::overlap(node->getEntry(i)->rectangle, rectangle)){
            auto childResults = searchUtil(node->getEntry(i)->getChild(), rectangle);
            result.insert(result.end(), childResults.begin(), childResults.end()); 
        }
    }
    return result;
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::search(Point point){
    rectangle_t rectangle(point, point);
    return searchRectangle(rectangle);
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::search(Point min, Point max){
    rectangle_t rectangle(min, max);
    return searchRectangle(rectangle);
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::search(rectangle_t rectangle){
    return searchRectangle(rectangle);
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::searchPerRangeUtil(std::shared_ptr<node_t> node, Point point, double distance){
    if(node->isLeaf()){
        return node->getAllData(point, distance);
    }
    std::vector<DataType> result;
    for(std::size_t i = 0; i < node->size(); ++i){
        if(rectangle_t::minDist(point, node->getEntry(i)->rectangle) <= distance){
            auto childResults = searchPerRangeUtil(node->getEntry(i)->getChild(), point, distance);
            result.insert(result.end(), childResults.begin(), childResults.end()); 
        }
    }
    return result;
}

RTREE_TEMPLATE
std::vector<DataType> RTREE_DEFINITION::searchPerRange(Point point, double distance){
    if(!_root)
        return std::vector<DataType>();
    return searchPerRangeUtil(_root, point, distance);
}

RTREE_TEMPLATE
RTREE_DEFINITION::~RTree(){
    if(_root){
        _root->killSelf();
        _root.reset();
    }
}