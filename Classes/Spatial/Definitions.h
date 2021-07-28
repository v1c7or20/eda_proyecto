#ifndef EDA_PROYECTO_DEFINITIONS_H
#define EDA_PROYECTO_DEFINITIONS_H

#define RNODE_TEMPLATE template<typename Point, typename DataType>
#define RTREE_TEMPLATE template<typename Point, typename DataType, std::size_t MAXNODES, std::size_t MINNODES>

#define RTREE_DEFINITION RTree<Point, DataType, MAXNODES, MINNODES> 
#define RNODE_DEFINITION RNode<Point, DataType>
#define ENTRY_DEFINITION Entry<RNODE_DEFINITION, Point, DataType>


#endif // EDA_PROYECTO_DEFINITIONS_H