#include <initializer_list>
#include <iostream>
#include <string>
#include <cmath>   

class Figure {
protected:
    double *coords = nullptr;
    size_t size = 0;

public:
    Figure(int size);
    Figure(const Figure &f);  
    Figure& operator=(const Figure& other);  
    Figure(Figure&& other) noexcept;
    Figure& operator=(Figure&& other) noexcept;
    virtual ~Figure();

    virtual std::pair<double, double> CalculateCenter() = 0; 
    virtual operator double() const;
    bool operator==(const Figure &other);
    size_t GetSize() noexcept;
    double * GetCoords() noexcept;

    friend std::ostream& operator<<(std::ostream& os, Figure *f);
    friend std::istream& operator>>(std::istream& is, Figure *f);
};

class Hexagon : public Figure {
public:
    Hexagon() : Figure(6){};
    Hexagon(const Hexagon &f) : Figure(f){};
    Hexagon(Hexagon&& f) noexcept : Figure(std::move(f)) {};  
    Hexagon& operator=(Hexagon&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }

    std::pair<double, double> CalculateCenter() override; 
    operator double() const override;
    bool operator==(const Hexagon &other);

    friend std::ostream& operator<<(std::ostream& os, Hexagon *h);
    friend std::istream& operator>>(std::istream& is, Hexagon *h);
};

class Octagon : public Figure {
public:
    Octagon() : Figure(8){};  
    Octagon(const Octagon &f) : Figure(f){};
    Octagon(Octagon&& f) noexcept : Figure(std::move(f)) {};  
    Octagon& operator=(Octagon&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }

    std::pair<double, double> CalculateCenter() override;
    operator double() const override;
    bool operator==(const Octagon &other);

    friend std::ostream& operator<<(std::ostream& os, Octagon *o);
    friend std::istream& operator>>(std::istream& is, Octagon *o);
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {};
    Triangle(const Triangle &f) : Figure(f){};
    Triangle(Triangle&& f) noexcept : Figure(std::move(f)) {};  
    Triangle& operator=(Triangle&& other) noexcept {
        Figure::operator=(std::move(other));
        return *this;
    }

    std::pair<double, double> CalculateCenter() override;
    operator double() const override;
    bool operator==(const Triangle &other);

    friend std::ostream& operator<<(std::ostream& os, Triangle *t);
    friend std::istream& operator>>(std::istream& is, Triangle *t);
};

class Array {
    protected:
        Figure** data;
        size_t size_;
        size_t capacity_;

    public:
        Array();
        Array(const Array&) = delete;
        Array& operator=(const Array&) = delete;
        Array(Array&&) = delete;
        Array& operator=(Array&&) = delete;
        ~Array();
        
        void push_back(Figure* figure);
        void erase(size_t index);
        size_t size() const;
        bool empty() const;
        Figure* at(size_t index);
        const Figure* at(size_t index) const;
        void clear();
        
        private:
        void resize(size_t new_capacity);  
};