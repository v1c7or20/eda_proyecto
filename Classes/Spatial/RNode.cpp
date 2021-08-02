#include "RNode.h"

RNODE_TEMPLATE
RNode<Point, DataType>::RNode(bool leaf){
    this->_leaf = leaf;
}

RNODE_TEMPLATE
bool RNODE_DEFINITION::isLeaf(){
    return this->_leaf;
}

RNODE_TEMPLATE
std::size_t RNODE_DEFINITION::pickChild(rectangle_t rectangle){
    bool firstTime = true;
    double bestArea;
    double bestIncrease;
    std::size_t indexChild;
    for(std::size_t i = 0; i < this->_entries.size(); i++){
        rectangle_t currentRect = this->_entries[i]->rectangle;
        rectangle_t tempRect = rectangle_t::rectangleIncluding(currentRect, rectangle);
        double areaCurrentRect = currentRect.getRegion(false);
        double increase = tempRect.getRegion(false) - areaCurrentRect;
        if((increase < bestIncrease) || firstTime ||
            (increase == bestIncrease && areaCurrentRect < bestArea)){
            indexChild = i;
            bestArea = areaCurrentRect;
            bestIncrease = increase;
            firstTime = false;
        }
    }
    return indexChild;
}

RNODE_TEMPLATE
void RNODE_DEFINITION::add(std::shared_ptr<entry_t> entry){
    this->_entries.push_back(entry);
}

RNODE_TEMPLATE
std::size_t RNODE_DEFINITION::size(){ 
    return _entries.size(); 
}

RNODE_TEMPLATE
std::shared_ptr<ENTRY_DEFINITION> RNODE_DEFINITION::getEntry(std::size_t index){
    assert(0 <= index && index < size());
    return _entries[index];
}

RNODE_TEMPLATE
void RNODE_DEFINITION::popEntry(std::size_t index){
    assert(0 <= index && index < size());
    _entries.erase(_entries.begin() + index);
}

RNODE_TEMPLATE
void RNODE_DEFINITION::clearEntries(){
    _entries.clear();
}

RNODE_TEMPLATE
Rectangle<Point> RNODE_DEFINITION::getNodeMBR(){
    assert(!_entries.empty());
    rectangle_t finalRect = _entries[0]->rectangle;
    for(std::size_t i = 1; i < _entries.size(); ++i){
        finalRect = rectangle_t::rectangleIncluding(finalRect, _entries[i]->rectangle);
    }
    return finalRect;
}

RNODE_TEMPLATE
void RNODE_DEFINITION::setNewEntry(std::size_t index, std::shared_ptr<entry_t> entry){
    assert(0 <= index && index < _entries.size());
    _entries[index].reset();
    _entries[index] = entry;
}

RNODE_TEMPLATE
std::vector<DataType> RNODE_DEFINITION::getAllData(rectangle_t rectangle){
    std::vector<DataType> result;
    for(std::size_t i = 0; i < _entries.size(); ++i){
        if(rectangle_t::overlap(_entries[i]->rectangle, rectangle))
            result.push_back(_entries[i]->getData());
    }
    return result;
}

RNODE_TEMPLATE
std::vector<DataType> RNODE_DEFINITION::getAllData(Point point, double distance){
    std::vector<DataType> result;
    for(std::size_t i = 0; i < _entries.size(); ++i){
        if(rectangle_t::minDist(point, _entries[i]->rectangle) <= distance){
            result.push_back(_entries[i]->getData());
        }
    }
    return result;
}

RNODE_TEMPLATE
void RNODE_DEFINITION::killSelf(){
    if(isLeaf()){
        for(std::size_t i = 0; i < _entries.size(); ++i){
            _entries[i].reset();
        }
    }else{
        for(std::size_t i = 0; i < _entries.size(); ++i){
            _entries[i]->getChild()->killSelf();
            _entries[i].reset();
        }
    }
    _entries.clear();
}