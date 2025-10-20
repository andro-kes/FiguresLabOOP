#include "figure.h"
#include <iostream>

int main() {
    std::cout << "ТЕСТИРОВАНИЕ\n\n";
    
    Array figures;

    // Тест 1: Добавление фигур
    std::cout << "1. ДОБАВЛЕНИЕ ФИГУР В МАССИВ:\n";
    std::cout << "------------------------------\n";
    figures.push_back(new Hexagon());
    figures.push_back(new Octagon());
    figures.push_back(new Triangle());
    std::cout << "Размер массива: " << figures.size() << "\n\n";
    std::cout << "Введите координаты для шестиугольника" << ":\n";
    std::cin >> figures.at(0);
    std::cout << "Введите координаты для восьмиугольника" << ":\n";
    std::cin >> figures.at(1);
    std::cout << "Введите координаты для треугольника" << ":\n";
    std::cin >> figures.at(2);

    std::cout << "2. ВЫВОД ВСЕХ ФИГУР:\n";
    std::cout << "---------------------\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Фигура " << i + 1 << ":\n";
        std::cout << figures.at(i);
        
        auto center = figures.at(i)->CalculateCenter();
        double area = double(*figures.at(i));
        
        std::cout << "Центр: (" << center.first << ", " << center.second << ")\n";
        std::cout << "Площадь: " << area << "\n\n";
    }

    std::cout << "3. УДАЛЕНИЕ ПО ИНДЕКСУ:\n";
    std::cout << "-----------------------\n";
    std::cout << "Размер до удаления: " << figures.size() << "\n";
    if (figures.size() > 1) {
        figures.erase(1);
        std::cout << "Удалена фигура с индексом 1\n";
    }
    std::cout << "Размер после удаления: " << figures.size() << "\n\n";

    std::cout << "4. ОБЩАЯ ПЛОЩАДЬ:\n";
    std::cout << "------------------\n";
    double total_area = 0.0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total_area += double(*figures.at(i));
    }
    std::cout << "Общая площадь всех фигур: " << total_area << "\n\n";

    std::cout << "5. ПРОВЕРКА ДОСТУПА ПО ИНДЕКСУ:\n";
    std::cout << "-------------------------------\n";
    try {
        if (!figures.empty()) {
            std::cout << "Первая фигура:\n" << figures.at(0);
        }
        // Пытаемся получить доступ к несуществующему элементу
        figures.at(100);
    } catch (const std::out_of_range& e) {
        std::cout << "Ошибка: " << e.what() << "\n";
    }

    std::cout << "\n6. ПРОВЕРКА НА ПУСТОТУ:\n";
    std::cout << "-----------------------\n";
    std::cout << "Массив " << (figures.empty() ? "пуст" : "не пуст") << "\n";

    std::cout << "\nТЕСТИРОВАНИЕ ЗАВЕРШЕНО\n";
    
    return 0;
}