#include "figure.h"
#include <cmath>  

std::ostream& operator<<(std::ostream& os, Triangle *t) {
    os << "Координаты треугольника:" << "\n";
    for (size_t i = 0; i < 6; i+=2) {
        os << "x: " << t->coords[i] << " y: " << t->coords[i+1] << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Triangle *t) {
    for (size_t i = 0; i < 6; ++i) {
        is >> t->coords[i];
    }
    return is;
}

std::pair<double, double> Triangle::CalculateCenter() {  
    double x = (this->coords[0] + this->coords[2] + this->coords[4]) / 3.0;  
    double y = (this->coords[1] + this->coords[3] + this->coords[5]) / 3.0; 
    return std::pair<double, double>{x, y};
}

Triangle::operator double() const {  
    double x1 = this->coords[0];
    double y1 = this->coords[1];
    double x2 = this->coords[2];
    double y2 = this->coords[3];
    double x3 = this->coords[4];
    double y3 = this->coords[5];
    return std::abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

bool Triangle::operator==(const Triangle &other) {
    if (this->size != other.size) {
        return false;
    }
    for (size_t i = 0; i < this->size * 2; i++) {  
        if (this->coords[i] != other.coords[i]) { 
            return false;
        }
    }
    return true;
}