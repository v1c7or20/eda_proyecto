#ifndef EDA_PROYECTO_RECTANGLE_H
#define EDA_PROYECTO_RECTANGLE_H

#include <assert.h>

template<typename Point>
struct Rectangle{
    Rectangle(Point min, Point max):_min(min),_max(max){}
    Point _min;
    Point _max;
    std::size_t getDimension(){
        assert(_min.size() == _max.size());
        return this->_min.size();
    }
    double getArea(){
        assert(getDimension() == 2);
        const int x = 0, y = 1;
        double width = abs(_max.get(x) - _min.get(x));
        double height = abs(_max.get(y) - _min.get(y));
        return width * height;
    }
};

#endif //EDA_PROYECTO_RECTANGLE_H