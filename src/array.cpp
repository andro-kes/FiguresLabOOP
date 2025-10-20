#include "figure.h"
#include <stdexcept>

Array::Array() : data(nullptr), size_(0), capacity_(0) {}

Array::~Array() {
    clear();
}

void Array::push_back(Figure* figure) {
    if (size_ >= capacity_) {
        resize(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    
    data[size_] = figure;
    size_++;
}

void Array::erase(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    delete data[index];
    for (size_t i = index; i < size_ - 1; ++i) {
        data[i] = data[i + 1];
    }
    size_--;
    data[size_] = nullptr;
}

size_t Array::size() const {
    return size_;
}

bool Array::empty() const {
    return size_ == 0;
}

Figure* Array::at(size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const Figure* Array::at(size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void Array::clear() {
    for (size_t i = 0; i < size_; ++i) {
        delete data[i];
    }
    delete[] data;
    data = nullptr;
    size_ = 0;
    capacity_ = 0;
}

void Array::resize(size_t new_capacity) {
    Figure** new_data = new Figure*[new_capacity];
    try {
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = data[i];
        }
        for (size_t i = size_; i < new_capacity; ++i) {
            new_data[i] = nullptr;
        }
        delete[] data;
        data = new_data;
        capacity_ = new_capacity;
    } catch (...) {
        delete[] new_data;
        throw;
    }
}