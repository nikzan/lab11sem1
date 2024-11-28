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
    std::cin >> N;

    client min_client;
    min_client.duration = std::numeric_limits<int>::max();

    for (int i = 0; i < N; ++i) {
        client client_instance;
        std::cin >> client_instance.code >> client_instance.year >> client_instance.month >> client_instance.duration;

        if (client_instance.duration <= min_client.duration) {
            min_client = client_instance;
        }
    }

    std::cout << min_client.duration << " " << min_client.year << " " << min_client.month << std::endl;

    return 0;
}