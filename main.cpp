#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <fstream>
// #include <windows.h>

#include "linear_bin.h"
#include "rb_tree.h"
#include "hash.h"

using namespace std;
using namespace std::chrono;

int main() {
    // SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    vector<Ship> my_fleet(1000000);
    generate_vector(my_fleet);
    int sizes[13] = {100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 400000, 700000, 1000000};
    string name;
    
    cout << "Введите название корабля: ";
    cin >> name;
    cout << "\n";

    ofstream csv_file("results.csv");
    csv_file << "Size,Linear,BinTree,RBTree,HashTable\n";

    for (int s : sizes) {
        cout << "Размер массива: " << s << "\n";
        double time_linear, time_bin, time_rb, time_hash;

        vector<Ship> answer_linear;
        auto start = high_resolution_clock::now();
        search_linear(my_fleet, s, name, answer_linear);
        auto end = high_resolution_clock::now();
        time_linear = duration<double>(end - start).count();
        cout << "Линейный поиск: " << answer_linear.size() << " шт => " << time_linear << " сек\n";

        vector<Ship> answer_bin;
        TreeNode* root = nullptr;
        for (int i = 0; i < s; i++) root = create_bin_tree(root, my_fleet[i]);
        start = high_resolution_clock::now();
        search_bin_tree(root, name, answer_bin);
        end = high_resolution_clock::now();
        time_bin = duration<double>(end - start).count();
        cout << "Бинарное дерево: " << answer_bin.size() << " шт => " << time_bin << " сек\n";
        delete_bin_tree(root);

        vector<Ship> answer_rb;
        RBNode* root_rb = nullptr;
        for (int i = 0; i < s; i++) create_rb_tree(root_rb, my_fleet[i]);
        start = high_resolution_clock::now();
        search_rb_tree(root_rb, name, answer_rb);
        end = high_resolution_clock::now();
        time_rb = duration<double>(end - start).count();
        cout << "КЧ дерево:  " << answer_rb.size() << " шт => " << time_rb << " сек\n";
        delete_rb_tree(root_rb);

        vector<vector<Ship>> hash_array(10000);
        full_array(hash_array, my_fleet, s);
        vector<Ship> answer_hash;
        start = high_resolution_clock::now();
        find_ship(hash_array, name, answer_hash);
        end = high_resolution_clock::now();
        time_hash = duration<double>(end - start).count();
        cout << "Хэш-таблица: " << answer_hash.size() << " шт => " << time_hash << " сек\n\n";

        csv_file << s << "," << time_linear << "," << time_bin << "," << time_rb << "," << time_hash << "\n";
    }

    csv_file.close();
    cout << "Данные успешно сохранены в results.csv!\n";
    return 0;
}