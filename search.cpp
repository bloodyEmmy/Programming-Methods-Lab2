#include "search.h"

using namespace std;

void search_linear(vector<Ship>& my_vector, int n, string value, vector<Ship>& answer) {
    for (int i = 0; i < n; i++) {
        if (my_vector[i].ship_name == value) {
            answer.push_back(my_vector[i]);
        }
    }
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

void delete_bin_tree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    else {
        delete_bin_tree(node->left);
        delete_bin_tree(node->right);
        delete node;
    }
}

void search_bin_tree(TreeNode* node, string value, vector<Ship>& answer) {
    if (node == nullptr) {
        return;
    }
    else {
        if (value == node->data.ship_name) {
            answer.push_back(node->data);
            search_bin_tree(node->left, value, answer);
        }
        else if (value < node->data.ship_name) {
            search_bin_tree(node->left, value, answer);
        }
        else {
            search_bin_tree(node->right, value, answer);
        }
    }
}