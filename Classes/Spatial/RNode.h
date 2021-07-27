#ifndef EDA_PROYECTO_RNODE_H
#define EDA_PROYECTO_RNODE_H

#include <vector>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <variant>
#include "Rectangle.h"
#define RNODE_POINTER 0

template<typename Point, typename DataType>
class RNode{
private:
    using rectangle_t = Rectangle<Point>;
protected:
    struct Branch{
        rectangle_t rectangle;
        std::variant<std::shared_ptr<RNode>, DataType> element;
        Branch()= default;
        Branch(rectangle_t rectangle, std::shared_ptr<RNode> child){
            this->rectangle = rectangle;
            this->element = child;
        }
        Branch(rectangle_t rectangle, DataType data){
            this->rectangle = rectangle;
            this->element = data;
        }
    };
private:
    std::shared_ptr<RNode> pickChild(rectangle_t rectangle);
public:
    RNode()= default;
    explicit RNode(bool leaf);
    bool isLeaf();
    void add(rectangle_t rectangle, DataType data);
    std::size_t size();
    static rectangle_t rectangleIncluding(rectangle_t rectA, rectangle_t rectB);
    void createBranch(rectangle_t rectangle, DataType data);
private:
    bool _leaf{};
    std::vector<std::shared_ptr<Branch>> _branches;
};

#endif // EDA_PROYECTO_RNODE_H