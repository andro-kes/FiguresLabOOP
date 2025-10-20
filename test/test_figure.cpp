#include "../src/figure.h"
#include <gtest/gtest.h>
#include <cmath>

// Тесты для Triangle
TEST(TriangleTest, DefaultConstructor) {
    Triangle t;
    EXPECT_EQ(t.GetSize(), 3);
}

TEST(TriangleTest, CalculateCenter) {
    Triangle t;
    // Треугольник с координатами (0,0), (1,0), (0,1)
    double* coords = t.GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) {
        coords[i] = test_coords[i];
    }
    
    auto center = t.CalculateCenter();
    EXPECT_NEAR(center.first, 0.333, 0.01);
    EXPECT_NEAR(center.second, 0.333, 0.01);
}

TEST(TriangleTest, AreaCalculation) {
    Triangle t;
    // Треугольник с координатами (0,0), (1,0), (0,1) - площадь = 0.5
    double* coords = t.GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) {
        coords[i] = test_coords[i];
    }
    
    double area = double(t);
    EXPECT_NEAR(area, 0.5, 0.01);
}

TEST(TriangleTest, EqualityOperator) {
    Triangle t1, t2;
    double* coords1 = t1.GetCoords();
    double* coords2 = t2.GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) {
        coords1[i] = test_coords[i];
        coords2[i] = test_coords[i];
    }
    
    EXPECT_TRUE(t1 == t2);
}

// Тесты для Hexagon
TEST(HexagonTest, DefaultConstructor) {
    Hexagon h;
    EXPECT_EQ(h.GetSize(), 6);
}

TEST(HexagonTest, CalculateCenter) {
    Hexagon h;
    // Правильный шестиугольник с центром в (0,0)
    double* coords = h.GetCoords();
    double test_coords[] = {1,0, 0.5,0.866, -0.5,0.866, -1,0, -0.5,-0.866, 0.5,-0.866};
    for (int i = 0; i < 12; ++i) {
        coords[i] = test_coords[i];
    }
    
    auto center = h.CalculateCenter();
    EXPECT_NEAR(center.first, 0.0, 0.01);
    EXPECT_NEAR(center.second, 0.0, 0.01);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon h;
    // Правильный шестиугольник с радиусом 1
    double* coords = h.GetCoords();
    double test_coords[] = {1,0, 0.5,0.866, -0.5,0.866, -1,0, -0.5,-0.866, 0.5,-0.866};
    for (int i = 0; i < 12; ++i) {
        coords[i] = test_coords[i];
    }
    
    double area = double(h);
    EXPECT_NEAR(area, 2.598, 0.01);
}

// Тесты для Octagon
TEST(OctagonTest, DefaultConstructor) {
    Octagon o;
    EXPECT_EQ(o.GetSize(), 8);
}

TEST(OctagonTest, CalculateCenter) {
    Octagon o;
    // Правильный восьмиугольник с центром в (0,0)
    double* coords = o.GetCoords();
    double test_coords[] = {1,0, 0.707,0.707, 0,1, -0.707,0.707, -1,0, -0.707,-0.707, 0,-1, 0.707,-0.707};
    for (int i = 0; i < 16; ++i) {
        coords[i] = test_coords[i];
    }
    
    auto center = o.CalculateCenter();
    EXPECT_NEAR(center.first, 0.0, 0.01);
    EXPECT_NEAR(center.second, 0.0, 0.01);
}

// Тесты для Array
TEST(ArrayTest, DefaultConstructor) {
    Array arr;
    EXPECT_EQ(arr.size(), 0);
    EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, PushBack) {
    Array arr;
    arr.push_back(new Triangle());
    EXPECT_EQ(arr.size(), 1);
    EXPECT_FALSE(arr.empty());
}

TEST(ArrayTest, MultiplePushBack) {
    Array arr;
    arr.push_back(new Triangle());
    arr.push_back(new Hexagon());
    arr.push_back(new Octagon());
    EXPECT_EQ(arr.size(), 3);
}

TEST(ArrayTest, AtMethod) {
    Array arr;
    Triangle* t = new Triangle();
    arr.push_back(t);
    
    Figure* retrieved = arr.at(0);
    EXPECT_EQ(retrieved, t);
}

TEST(ArrayTest, AtMethodConst) {
    Array arr;
    arr.push_back(new Triangle());
    
    const Array& const_arr = arr;
    const Figure* retrieved = const_arr.at(0);
    EXPECT_NE(retrieved, nullptr);
}

TEST(ArrayTest, EraseMethod) {
    Array arr;
    arr.push_back(new Triangle());
    arr.push_back(new Hexagon());
    arr.push_back(new Octagon());
    
    EXPECT_EQ(arr.size(), 3);
    arr.erase(1); // Удаляем второй элемент
    EXPECT_EQ(arr.size(), 2);
}

TEST(ArrayTest, ClearMethod) {
    Array arr;
    arr.push_back(new Triangle());
    arr.push_back(new Hexagon());
    
    EXPECT_EQ(arr.size(), 2);
    arr.clear();
    EXPECT_EQ(arr.size(), 0);
    EXPECT_TRUE(arr.empty());
}

TEST(ArrayTest, OutOfRangeAccess) {
    Array arr;
    arr.push_back(new Triangle());
    
    EXPECT_THROW(arr.at(1), std::out_of_range);
    EXPECT_THROW(arr.at(100), std::out_of_range);
}

TEST(ArrayTest, OutOfRangeErase) {
    Array arr;
    arr.push_back(new Triangle());
    
    EXPECT_THROW(arr.erase(1), std::out_of_range);
    EXPECT_THROW(arr.erase(100), std::out_of_range);
}

TEST(ArrayTest, EmptyArrayOperations) {
    Array arr;
    EXPECT_TRUE(arr.empty());
    EXPECT_EQ(arr.size(), 0);
    
    EXPECT_THROW(arr.erase(0), std::out_of_range);
}

TEST(ArrayTest, TotalAreaCalculation) {
    Array arr;
    
    // Добавляем треугольник с площадью 0.5
    Triangle* t = new Triangle();
    double* t_coords = t->GetCoords();
    double test_t_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) t_coords[i] = test_t_coords[i];
    arr.push_back(t);
    
    // Добавляем шестиугольник с известной площадью
    Hexagon* h = new Hexagon();
    double* h_coords = h->GetCoords();
    double test_h_coords[] = {1,0, 0.5,0.866, -0.5,0.866, -1,0, -0.5,-0.866, 0.5,-0.866};
    for (int i = 0; i < 12; ++i) h_coords[i] = test_h_coords[i];
    arr.push_back(h);
    
    double total_area = 0.0;
    for (size_t i = 0; i < arr.size(); ++i) {
        total_area += double(*arr.at(i));
    }
    
    EXPECT_GT(total_area, 0.0);
}

TEST(FigureTest, CopyConstructor) {
    Triangle original;
    double* original_coords = original.GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) original_coords[i] = test_coords[i];
    
    Triangle copy(original);
    double* copy_coords = copy.GetCoords();
    
    // Проверяем, что координаты скопированы
    for (int i = 0; i < 6; ++i) {
        EXPECT_EQ(original_coords[i], copy_coords[i]);
    }
    
    // Проверяем, что это разные объекты
    copy_coords[0] = 5.0;
    EXPECT_NE(original_coords[0], copy_coords[0]);
}

TEST(PolymorphismTest, FigurePointerOperations) {
    Figure* figure = new Triangle();
    double* coords = figure->GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) coords[i] = test_coords[i];
    
    auto center = figure->CalculateCenter();
    double area = double(*figure);
    
    EXPECT_NEAR(center.first, 0.333, 0.01);
    EXPECT_NEAR(area, 0.5, 0.01);
    
    delete figure;
}

TEST(MoveSemanticsTest, MoveConstructor) {
    Triangle original;
    double* original_coords = original.GetCoords();
    double test_coords[] = {0, 0, 1, 0, 0, 1};
    for (int i = 0; i < 6; ++i) original_coords[i] = test_coords[i];
    
    Triangle moved(std::move(original));
    double* moved_coords = moved.GetCoords();
    
    // Проверяем, что координаты перемещены
    for (int i = 0; i < 6; ++i) {
        EXPECT_EQ(moved_coords[i], test_coords[i]);
    }
    
    // Проверяем, что оригинальный объект в валидном состоянии
    EXPECT_EQ(original.GetCoords(), nullptr);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}