#include "search.h"

using namespace std;

vector<Ship> search_linear(vector<Ship>& my_vector, int n, string value) {
    vector<Ship> answer;
    for (int i = 0; i < n; i++) {
        if (my_vector[i].ship_name == value) {
            answer.push_back(my_vector[i]);
        }
    }
    return answer;
}

TreeNode* create_bin_tree(TreeNode* node, Ship value) {
    if (node == nullptr) {
        node = new TreeNode(value);
    }
    else {
        if (value.ship_name <= node->data.ship_name) {
            node->left = create_bin_tree(node->left, value);
        }
        else {
            node->right = create_bin_tree(node->right, value);
        }
    }
    return node;
}