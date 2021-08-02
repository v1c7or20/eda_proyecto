#ifndef EDA_PROYECTO_RNODE_H
#define EDA_PROYECTO_RNODE_H

#include <vector>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <variant>
#include "Definitions.h"
#include "Entry.h"

template<typename Point, typename DataType>
class RNode{
private:
    using rectangle_t = Rectangle<Point>;
    using entry_t = Entry<RNode, Point, DataType>;
public:
    RNode()=default;
    explicit RNode(bool leaf);
    bool isLeaf();
    std::size_t pickChild(rectangle_t rectangle);
    void add(std::shared_ptr<entry_t> entry);
    std::size_t size();
    std::shared_ptr<entry_t> getEntry(std::size_t index);
    void popEntry(std::size_t index);
    void clearEntries();
    rectangle_t getNodeMBR();
    void setNewEntry(std::size_t index, std::shared_ptr<entry_t> entry);
    std::vector<DataType> getAllData(rectangle_t rectangle);
    std::vector<DataType> getAllData(Point point, double distance);
    void killSelf();
private:
    bool _leaf{};
    std::vector<std::shared_ptr<entry_t>> _entries;
};

#endif // EDA_PROYECTO_RNODE_H