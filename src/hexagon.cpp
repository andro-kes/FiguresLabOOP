#include "figure.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os, Hexagon *h) {
    os << "Координаты шестиугольника:" << "\n"; 
    for (size_t i = 0; i < 12; i+=2) {
        os << "x: " << h->coords[i] << " y: " << h->coords[i+1] << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Hexagon *h) {
    for (size_t i = 0; i < 12; ++i) {
        is >> h->coords[i];
    }
    return is;
}

std::pair<double, double> Hexagon::CalculateCenter() { 
    double xSum = 0.0, ySum = 0.0;
    for (int i = 0; i < 6; i++) {
        xSum += this->coords[2 * i];
        ySum += this->coords[2 * i + 1]; 
    }
    return std::pair<double, double>{xSum / 6, ySum / 6};
}

Hexagon::operator double() const {  
    double area = 0.0;
    for (int i = 0; i < 6; i++) {
        int j = (i + 1) % 6;
        area += this->coords[2 * i] * this->coords[2 * j + 1] - this->coords[2 * j] * this->coords[2 * i + 1];
    }
    return std::abs(area) / 2.0;
}

bool Hexagon::operator==(const Hexagon &other) {
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