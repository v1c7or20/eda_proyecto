#ifndef EDA_PROYECTO_POINT_H
#define EDA_PROYECTO_POINT_H

#include <cmath>
#include <array>
#include <algorithm> 
using distance_t = double;

template<typename DataType, std::size_t DIM>
class Point
{
public:
    Point() {
        std::fill_n(_values.begin(), DIM, DataType(0));
    }

    explicit Point(const std::array<DataType, DIM>& init_array):_values(init_array){ }

    bool operator==(const Point<DataType, DIM>& p) const;
    bool operator<(const Point<DataType, DIM>& p) const;
    DataType operator[](std::size_t index) const;

    distance_t distance(const Point<DataType, DIM>& p) const;

    DataType get(std::size_t pos) const{
        return _values.at(pos);
    }

    std::size_t size(){
        return DIM;
    }

private:
    std::array<DataType, DIM> _values;
};

template<typename DataType, std::size_t DIM>
inline bool Point<DataType, DIM>::operator==(const Point<DataType, DIM>& p) const {
    for(std::size_t I=0;I<DIM;I++){
        if(this->_values.at(I) != p._values.at(I))
            return false;
    }
    return true;
}

template<typename DataType, std::size_t DIM>
inline bool Point<DataType, DIM>::operator<(const Point<DataType, DIM>& p) const {
    for(std::size_t I=0;I<DIM;I++){
        if(this->_values.at(I) >= p._values.at(I))
            return false;
    }
    return true;
}

template<typename DataType, std::size_t DIM>
inline distance_t Point<DataType, DIM>::distance(const Point<DataType, DIM>& p) const {
    double acum=0.0;

    for(std::size_t I=0;I<DIM;I++){
        acum += (this->_values.at(I) - p._values.at(I)) * (this->_values.at(I) - p._values.at(I));
    }
    return sqrt(acum);
}

template<typename DataType, std::size_t DIM>
inline DataType Point<DataType, DIM>::operator[](std:: size_t index) const {
    return this->get(index);
}

#endif //EDA_PROYECTO_POINT_H