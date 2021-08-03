#ifndef EDA_PROYECTO_RECTANGLE_H
#define EDA_PROYECTO_RECTANGLE_H

#include <cassert>
#include <cmath>

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
                side = 0.0000001;
            region *= side;
        }
        return region;
    }
    Rectangle& operator=(const Rectangle& rect){
        this->_min = rect._min;
        this->_max = rect._max;
        return *this;
    }
    bool operator==(const Rectangle& rect){
        return _min == rect._min && _max == rect._max;
    }
    static Rectangle rectangleIncluding(Rectangle rectA, Rectangle rectB){
        assert(rectA.getDimension() == rectB.getDimension());
        Point min, max;
        for(std::size_t i = 0; i < rectA.getDimension(); ++i){
            min.set(i, std::min(rectA._min.get(i), rectB._min.get(i)));
            max.set(i, std::max(rectA._max.get(i), rectB._max.get(i)));
        }
        return Rectangle(min, max);
    }
    static double areaIncrease(Rectangle rectA, Rectangle rectB) {
        Rectangle rect = rectangleIncluding(rectA, rectB);
        return rect.getRegion(false) - rectA.getRegion(false);
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
    static double minDist(Point point, Rectangle rectangle){
        assert(point.size() == rectangle.getDimension());
        double result = 0.0;
        for(std::size_t i = 0; i < point.size(); ++i){
            if(point.get(i) < rectangle._min.get(i)){
                result += std::pow(point.get(i) - rectangle._min.get(i), 2);
            }else if(point.get(i) > rectangle._max.get(i)){
                result += std::pow(point.get(i) - rectangle._max.get(i), 2);
            }
        }
        return std::sqrt(result);
    }
};

#endif //EDA_PROYECTO_RECTANGLE_H
