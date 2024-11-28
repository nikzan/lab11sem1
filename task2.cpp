#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

enum class shape_type { Circle, Square, Line };

struct shape {
    shape_type type;
    std::string color;
    union {
        short int radius; // для круга
        int side;         // для квадрата
        float length;     // для отрезка
    } data;
};

void input_shape(shape &shape) {
    int type;
    std::cout << "Введите тип фигуры (0 - круг, 1 - квадрат, 2 - отрезок): ";
    std::cin >> type;
    shape.type = static_cast<shape_type>(type);

    std::cout << "Введите цвет фигуры: ";
    std::cin >> shape.color;

    switch (shape.type) {
        case shape_type::Circle:
            std::cout << "Введите радиус круга: ";
            std::cin >> shape.data.radius;
            break;
        case shape_type::Square:
            std::cout << "Введите размер стороны квадрата: ";
            std::cin >> shape.data.side;
            break;
        case shape_type::Line:
            std::cout << "Введите длину отрезка: ";
            std::cin >> shape.data.length;
            break;
    }
}

void save_shape_to_file(const std::vector<shape> &shapes, const std::string &filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи: " << filename << std::endl;
        return;
    }
    for (const auto &shape : shapes) {
        file << static_cast<int>(shape.type) << " " << shape.color << " ";
        switch (shape.type) {
            case shape_type::Circle:
                file << shape.data.radius;
                break;
            case shape_type::Square:
                file << shape.data.side;
                break;
            case shape_type::Line:
                file << shape.data.length;
                break;
        }
        file << std::endl;
    }
}

void print_shapes_from_file(const std::string &filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения: " << filename << std::endl;
        return;
    }
    int type;
    std::string color;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::left << std::setw(20) << "Тип"
              << std::setw(20) << "Цвет"
              << std::setw(20) << "Параметр" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    while (file >> type >> color) {
        std::cout << std::left << std::setw(20);
        switch (static_cast<shape_type>(type)) {
            case shape_type::Circle:
                std::cout << "Круг";
                break;
            case shape_type::Square:
                std::cout << "Квадрат";
                break;
            case shape_type::Line:
                std::cout << "Отрезок";
                break;
        }
        std::cout << std::setw(20) << color;
        switch (static_cast<shape_type>(type)) {
            case shape_type::Circle: {
                short int radius;
                file >> radius;
                std::cout << std::setw(20) << radius;
                break;
            }
            case shape_type::Square: {
                int side;
                file >> side;
                std::cout << std::setw(20) << side;
                break;
            }
            case shape_type::Line: {
                float length;
                file >> length;
                std::cout << std::setw(20) << length;
                break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------" << std::endl;
}

int main() {
    int N;
    std::cout << "Введите количество фигур: ";
    std::cin >> N;

    std::vector<shape> shapes(N);
    for (int i = 0; i < N; ++i) {
        input_shape(shapes[i]);
    }

    std::string filename = "/Users/nikzan/CLionProjects/lab11sem1/shapes.txt";
    save_shape_to_file(shapes, filename);
    print_shapes_from_file(filename);

    /* Пример данных файла
    0 red 1
    1 blue 2
    2 green 3.5
     */

    /* Пример вывода
    ----------------------------------------
    Тип             Цвет            Параметр
    ----------------------------------------
    Круг            red                 1
    Квадрат         blue                2
    Отрезок         green               3.5
    ----------------------------------------
     */

    return 0;
}

