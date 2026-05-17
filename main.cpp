#include <iostream>

#include "search.h"

using namespace std;

int main() {
    vector<Ship> my_fleet(1000000);
    generate_vector(my_fleet);

    int sizes[13] = {100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 400000, 700000, 1000000};
    string name;
    cout << "Введите название корабля: ";
    cin >> name;
    for (int s: sizes) {
        vector<Ship> answer = search_linear(my_fleet, s, name);
    }
}