#include <iostream>
#include <limits>

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

    client min_client;
    min_client.duration = std::numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        client client_instance;
        while (!(std::cin >> client_instance.code >> client_instance.year >> client_instance.month >> client_instance.duration) ||
               client_instance.year < 0 || client_instance.month < 1 || client_instance.month > 12 || client_instance.duration < 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите корректные данные клиента (код, год, месяц, продолжительность): ";
        }

        if (client_instance.duration <= min_client.duration) {
            min_client = client_instance;
        }
    }

    std::cout << min_client.duration << " " << min_client.year << " " << min_client.month << std::endl;

    return 0;
}