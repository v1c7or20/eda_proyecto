#ifndef EDA_PROYECTO_RECTANGLE_H
#define EDA_PROYECTO_RECTANGLE_H

#include <cassert>

template<typename Point>
struct Rectangle{
    Point _min;
    Point _max;
    Rectangle()= default;
    Rectangle(const Rectangle<Point>& rect) : _min(rect._min), _max(rect._max){}
    Rectangle(Point min, Point max):_min(min),_max(max){}
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
    Rectangle& operator=(const Rectangle& rect){
        this->_min = rect._min;
        this->_max = rect._max;
        return *this;
    }
};

#endif //EDA_PROYECTO_RECTANGLE_H