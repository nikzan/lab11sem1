#include <iostream>
#include <limits>
#include <map>
struct client {
    int code;
    int year;
    int month;
    int duration;
};

int main() {
    int N;
    while (!(std::cin >> N) || N <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Введите корректное количество клиентов: ";
    }

    std::map<int, int> client_durations;

    for (int i = 0; i < N; ++i) {
        client client_instance;
        while (!(std::cin >> client_instance.code >> client_instance.year >> client_instance.month >> client_instance.duration) ||
               client_instance.year < 0 || client_instance.month < 1 || client_instance.month > 12 || client_instance.duration < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите корректные данные клиента (код, год, месяц, продолжительность): ";
        }

        client_durations[client_instance.code] += client_instance.duration;
    }

    int min_duration = std::numeric_limits<int>::max();
    int min_code = -1;
    for (const auto &entry : client_durations) {
        if (entry.second < min_duration) {
            min_duration = entry.second;
            min_code = entry.first;
        }
    }

    std::cout << "Код клиента с минимальной продолжительностью: " << min_code << ", продолжительность: " << min_duration << std::endl;

    return 0;
}