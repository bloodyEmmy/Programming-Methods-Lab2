#include "hash.h"

using namespace std;

void full_array(vector<vector<Ship>>& vector_array, vector<Ship>& fleet, int s) {
    for (int i = 0; i < s; i++) {
            int hash_val = 0;
            for (char c : fleet[i].ship_name) {
                hash_val += c;
            }
            hash_val = abs(hash_val) % 10000;
            vector_array[hash_val].push_back(fleet[i]);
        }
}

void find_ship(vector<vector<Ship>>& vector_array, string name, vector<Ship>& answer) {
    int hash_val = 0;
    for (char c : name) {
        hash_val += c;
    }
    hash_val = abs(hash_val) % 10000;
    for (int i = 0; i < vector_array[hash_val].size(); i++) {
        if (vector_array[hash_val][i].ship_name == name) {
            answer.push_back(vector_array[hash_val][i]);
        }
    }
}