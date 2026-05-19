#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "linear_bin.h"
#include "rb_tree.h"
#include "hash.h"

using namespace std;
using namespace std::chrono;

int main() {
    vector<Ship> my_fleet(1000000);
    generate_vector(my_fleet);
    int sizes[13] = {100, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 400000, 700000, 1000000};
    string name;
    
    cout << "Введите название корабля: ";
    cin >> name;
    cout << "\n";

    for (int s : sizes) {
        cout << "Размер массива: " << s << "\n";

        vector<Ship> answer_linear;
        auto start = high_resolution_clock::now();
        for (int k = 0; k < 10; k++) {
            answer_linear.clear();
            search_linear(my_fleet, s, name, answer_linear);
        }
        auto end = high_resolution_clock::now();
        duration<double> diff = end - start;
        cout << "Линейный поиск: " << answer_linear.size() << " шт. | Время (10 раз): " << diff.count() << " сек\n";

        vector<Ship> answer_bin;
        TreeNode* root = nullptr;
        for (int i = 0; i < s; i++) {
            root = create_bin_tree(root, my_fleet[i]);
        }
        start = high_resolution_clock::now();
        for (int k = 0; k < 10; k++) {
            answer_bin.clear();
            search_bin_tree(root, name, answer_bin);
        }
        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Бинарное дерево: " << answer_bin.size() << " шт. | Время (10 раз): " << diff.count() << " сек\n";
        delete_bin_tree(root);

        vector<Ship> answer_rb;
        RBNode* root_rb = nullptr;
        for (int i = 0; i < s; i++) {
            create_rb_tree(root_rb, my_fleet[i]);
        }
        start = high_resolution_clock::now();
        for (int k = 0; k < 10; k++) {
            answer_rb.clear();
            search_rb_tree(root_rb, name, answer_rb);
        }
        end = high_resolution_clock::now();
        diff = end - start;
        cout << "КЧ дерево:       " << answer_rb.size() << " шт. | Время (10 раз): " << diff.count() << " сек\n";
        delete_rb_tree(root_rb);

        vector<vector<Ship>> hash_array(10000);
        full_array(hash_array, my_fleet, s);
        
        vector<Ship> answer_hash;
        start = high_resolution_clock::now();
        for (int k = 0; k < 10; k++) {
            answer_hash.clear();
            int target_hash = 0;
            for (char c : name) {
                target_hash += c;
            }
            target_hash = abs(target_hash) % 10000;
            
            for (size_t i = 0; i < hash_array[target_hash].size(); i++) {
                if (hash_array[target_hash][i].ship_name == name) {
                    answer_hash.push_back(hash_array[target_hash][i]);
                }
            }
        }
        end = high_resolution_clock::now();
        diff = end - start;
        cout << "Хэш-таблица:     " << answer_hash.size() << " шт. | Время (10 раз): " << diff.count() << " сек\n\n";
    }

    return 0;
}