#include "hash.h"

using namespace std;

void full_array(vector<vector<Ship>>& vector_array, vector<Ship> fleet, int s) {
    for (int i = 0; i < s; i++) {
            int hash_val = 0;
            for (char c : fleet[i].ship_name) {
                hash_val += c;
            }
            hash_val = abs(hash_val) % 10000;
            vector_array[hash_val].push_back(fleet[i]);
        }
}