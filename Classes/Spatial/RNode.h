#ifndef EDA_PROYECTO_RNODE_H
#define EDA_PROYECTO_RNODE_H

#include <vector>
#include <algorithm>
#include <cstdint>
#include <memory>
#include <variant>
#define RNODE_POINTER 0

template<typename Rectangle, typename Point, typename DataType>
class RNode{
protected:
    struct Branch{
        Rectangle rectangle;
        std::variant<std::shared_ptr<RNode>, DataType> element;
        Branch()= default;
        Branch(Rectangle rectangle, std::shared_ptr<RNode> child){
            this->rectangle = rectangle;
            this->element = child;
        }
        Branch(Rectangle rectangle, DataType data){
            this->rectangle = rectangle;
            this->element = data;
        }
    };
private:
    std::shared_ptr<RNode> pickChild(Rectangle rectangle);
public:
    RNode()= default;
    explicit RNode(bool leaf);
    bool isLeaf();
    void add(Rectangle rectangle, DataType data);
    std::size_t size();
    static Rectangle rectangleIncluding(Rectangle rectA, Rectangle rectB);
    void createBranch(Rectangle rectangle, DataType data);
private:
    bool _leaf{};
    std::vector<Branch> _branches;
};

#endif // EDA_PROYECTO_RNODE_H