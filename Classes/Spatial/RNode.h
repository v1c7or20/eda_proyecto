#ifndef EDA_PROYECTO_RNODE_H
#define EDA_PROYECTO_RNODE_H

#include <vector>

template<typename Rectangle, typename Point>
class RNode{
public:
    RNode();
    RNode(bool leaf); 
    bool isLeaf();
    void add(Rectangle rectangle);
    std::size_t size();
private:
    bool _leaf;
    std::vector<Rectangle> rectangles;
    std::vector<std::shared_ptr<RNode>> _children;
    Rectangle _mbr;
};

#endif // EDA_PROYURE_RNODE_H