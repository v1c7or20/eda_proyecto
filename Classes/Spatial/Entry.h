#ifndef EDA_PROYECTO_ENTRY_H
#define EDA_PROYECTO_ENTRY_H

#include "Rectangle.h"

template <typename Node, typename Point, typename DataType>
class Entry{
private:
    using rectangle_t = Rectangle<Point>;
    using node_t = Node;
public:
    rectangle_t rectangle;
    std::variant<std::shared_ptr<node_t>, DataType> element;

    Entry()= default;
    Entry(rectangle_t rectangle, std::shared_ptr<node_t> child){
        this->rectangle = rectangle;
        this->element = child;
    }
    Entry(rectangle_t rectangle, DataType data){
        this->rectangle = rectangle;
        this->element = data;
    }
    std::shared_ptr<node_t> getChild(){
        return std::get<std::shared_ptr<node_t>>(element);
    }

    DataType getData(){
        return std::get<DataType>(element);
    }

    rectangle_t getRectangle(){
        return this->rectangle;
    }
};

#endif // EDA_PROYECTO_ENTRY_H