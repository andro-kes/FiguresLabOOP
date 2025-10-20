#include <iostream>
#include "figure.h"

Figure::Figure(int size) {
    this->size = size;
    if (size > 0) {
        this->coords = new double[size * 2];
    } else {
        this->coords = nullptr;
    }
}

Figure::Figure(const Figure &f) {
    this->size = f.size;
    if (f.coords != nullptr && f.size > 0) {
        this->coords = new double[this->size * 2];
        for (size_t i = 0; i < this->size * 2; ++i) {
            coords[i] = f.coords[i];
        }
    } else {
        this->coords = nullptr;
    }
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        delete[] coords;
        size = other.size;
        if (other.coords != nullptr && other.size > 0) {
            coords = new double[size * 2];
            for (size_t i = 0; i < size * 2; ++i) {
                coords[i] = other.coords[i];
            }
        } else {
            coords = nullptr;
        }
    }
    return *this;
}

Figure::Figure(Figure&& other) noexcept : coords(other.coords), size(other.size) {
    other.coords = nullptr;
    other.size = 0;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        delete[] coords;
        
        coords = other.coords;
        size = other.size;
        
        other.coords = nullptr;
        other.size = 0;
    }
    return *this;
}

Figure::~Figure() {
    delete[] coords;
}

std::ostream& operator<<(std::ostream& os, Figure *f) {
    for (size_t i = 0; i < f->size * 2; i+=2) {
        os << "x: " << f->coords[i] << " y: " << f->coords[i+1] << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure *f) {
    for (size_t i = 0; i < f->size * 2; ++i) {
        is >> f->coords[i];
    }
    return is;
}

Figure::operator double() const {  
    return 0.0;
}

bool Figure::operator==(const Figure &other) {
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

size_t Figure::GetSize() noexcept {
    return this->size;
}

double * Figure::GetCoords() noexcept {
    return this->coords;
}