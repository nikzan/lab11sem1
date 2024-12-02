#include <iostream>
#include <vector>
#include <string>

struct Car {
    std::string brand;
    std::string model;
    int year;
};

void add_car(std::vector<Car> &cars, const std::string &brand, const std::string &model, int year) {
    cars.push_back({brand, model, year});
}

void print_car(const Car &car) {
    std::cout << "Марка: " << car.brand << ", Модель: " << car.model << ", Год выпуска: " << car.year << std::endl;
}

void print_all_cars(const std::vector<Car> &cars) {
    for (const auto &car : cars) {
        print_car(car);
    }
}

int count_cars_by_brand(const std::vector<Car> &cars, const std::string &brand) {
    int count = 0;
    for (const auto &car : cars) {
        if (car.brand == brand) {
            ++count;
        }
    }
    return count;
}

std::vector<Car> find_cars_by_year_range(const std::vector<Car> &cars, int start_year, int end_year) {
    std::vector<Car> result;
    for (const auto &car : cars) {
        if (car.year >= start_year && car.year <= end_year) {
            result.push_back(car);
        }
    }
    return result;
}

double average_year(const std::vector<Car> &cars)
{
    if (cars.empty()) return 0.0;
    int total_years = 0;
    for (const auto &car : cars) {
        total_years += car.year;
    }
    return static_cast<double>(total_years) / cars.size();
}

int main(){
    std::vector<Car> cars;
    int num_cars;
    std::cout << "Введите количество автомобилей: ";
    while (!(std::cin >> num_cars) || num_cars <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите корректное количество автомобилей: ";
    }

    for (int i = 0; i < num_cars; ++i) {
        std::string brand, model;
        int year;
        std::cout << "Введите марку автомобиля: ";
        while (!(std::cin >> brand) || brand.empty()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите корректную марку автомобиля: ";
        }
        std::cout << "Введите модель автомобиля: ";
        while (!(std::cin >> model) || model.empty()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите корректную модель автомобиля: ";
        }
        std::cout << "Введите год выпуска автомобиля: ";
        while (!(std::cin >> year) || year < 1886 || year > 2024) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите корректный год выпуска автомобиля (1886-2024): ";
        }
        add_car(cars, brand, model, year);
    }
    std::cout << "Все автомобили:" << std::endl;
    print_all_cars(cars);

    std::string brand = "Tesla";
    std::cout << "Количество автомобилей марки " << brand << ": " << count_cars_by_brand(cars, brand) << std::endl;

    int start_year = 2010, end_year = 2015;
    std::cout << "Автомобили в диапазоне годов выпуска с " << start_year << " по " << end_year << ":" << std::endl;
    auto cars_in_range = find_cars_by_year_range(cars, start_year, end_year);
    print_all_cars(cars_in_range);

    std::cout << "Средний год выпуска всех автомобилей: " << average_year(cars) << std::endl;

    return 0;
}