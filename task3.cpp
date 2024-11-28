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
    add_car(cars, "Porsche", "911", 2010);
    add_car(cars, "Tesla", "Model S", 2015);
    add_car(cars, "Ford", "Mustang", 2022);

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