#include "figure.h"
#include <cmath>

std::ostream& operator<<(std::ostream& os, Octagon *h) {
    os << "Координаты восьмиугольника:" << "\n";  
    for (size_t i = 0; i < 16; i+=2) {
        os << "x: " << h->coords[i] << " y: " << h->coords[i+1] << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Octagon *h) {
    for (size_t i = 0; i < 16; ++i) {
        is >> h->coords[i];
    }
    return is;
}

std::pair<double, double> Octagon::CalculateCenter() {
    double x_sum = 0.0, y_sum = 0.0;
    for (int i = 0; i < 8; i++) {
        x_sum += this->coords[2 * i];   
        y_sum += this->coords[2 * i + 1]; 
    }
    return std::pair<double, double>{x_sum / 8, y_sum / 8};
}

Octagon::operator double() const { 
    double area = 0.0;
    for (int i = 0; i < 8; i++) {
        int j = (i + 1) % 8; 
        area += this->coords[2 * i] * this->coords[2 * j + 1] - 
                this->coords[2 * j] * this->coords[2 * i + 1];
    }
    return std::abs(area) / 2.0;
}

bool Octagon::operator==(const Octagon &other) {
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

