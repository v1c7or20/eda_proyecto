#ifndef EDA_PROYECTO_RTREE_H
#define EDA_PROYECTO_RTREE_H

#include <memory>
#include <assert.h>
template<typename Node, typename Rectangle, typename Point>
class RTree{
private:
    void insertUtil(std::shared_ptr<Node> node, Rectangle rectangle);
    bool checkRNode(std::shared_ptr<Node> node);
public:
    RTree();
    RTree(std::size_t MAXNODES, std::size_t MINNODES);
    void insert(Point new_point);
    bool overlap(Rectangle rect1, Rectangle rect2);
private:
    std::shared_ptr<Node> _root;
    std::size_t _MAXNODES;
    std::size_t _MINNODES;

};


#endif // EDA_PROYECTO_RTREE_H