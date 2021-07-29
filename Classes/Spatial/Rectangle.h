#ifndef EDA_PROYECTO_RECTANGLE_H
#define EDA_PROYECTO_RECTANGLE_H

#include <cassert>

template<typename Point>
struct Rectangle{
    Point _min{};
    Point _max{};
    Rectangle()= default;
    Rectangle(const Rectangle<Point>& rect) : _min(rect._min), _max(rect._max){}
    Rectangle(Point min, Point max):_min(min),_max(max){}
    std::size_t getDimension(){
        assert(_min.size() == _max.size());
        return this->_min.size();
    }
    double getRegion(bool nullRegion = true){
        if(_min == _max) return 0;
        double region = 1;
        for(std::size_t i = 0; i < getDimension(); ++i){
            double side = abs(_max.get(i) - _min.get(i));
            if(side == 0 && !nullRegion)
                side = 1;
            region *= side;
        }
        return region;
    }
    Rectangle& operator=(const Rectangle& rect){
        this->_min = rect._min;
        this->_max = rect._max;
        return *this;
    }
    static Rectangle rectangleIncluding(Rectangle rectA, Rectangle rectB){
        const int x = 0, y = 1;
        Point min({std::min(rectA._min.get(x), rectB._min.get(x)),
                    std::min(rectA._min.get(y), rectB._min.get(y))});
        Point max({std::max(rectA._max.get(x), rectB._max.get(x)),
                    std::max(rectA._max.get(y), rectB._max.get(y))});
        return Rectangle(min, max);
    }
    static double areaIncrease(Rectangle rectA, Rectangle rectB) {
        Rectangle rect = rectangleIncluding(rectA, rectB);
        return rect.getArea() - rectA.getArea();
    }
    static bool overlap(Rectangle rectA, Rectangle rectB){
        std::size_t dimension = rectA.getDimension();
        for(std::size_t index = 0; index < dimension; ++index){
            if (rectA._min.get(index) > rectB._max.get(index) ||
                rectB._min.get(index) > rectA._max.get(index))
            return false;
        }
        return true;
    }
};

#endif //EDA_PROYECTO_RECTANGLE_H
