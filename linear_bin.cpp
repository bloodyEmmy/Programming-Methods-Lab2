#include "linear_bin.h"
#include <vector>

using namespace std;

void search_linear(vector<Ship>& my_vector, int n, string value, vector<Ship>& answer) {
    for (int i = 0; i < n; i++) {
        if (my_vector[i].ship_name == value) {
            answer.push_back(my_vector[i]);
        }
    }
}

// ИТЕРАТИВНОЕ СОЗДАНИЕ (без рекурсии)
TreeNode* create_bin_tree(TreeNode* root, Ship value) {
    TreeNode* new_node = new TreeNode(value);
    if (root == nullptr) {
        return new_node;
    }
    
    TreeNode* current = root;
    while (true) {
        if (value.ship_name <= current->data.ship_name) {
            if (current->left == nullptr) {
                current->left = new_node;
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new_node;
                break;
            }
            current = current->right;
        }
    }
    return root;
}

// ИТЕРАТИВНЫЙ ПОИСК (без рекурсии)
void search_bin_tree(TreeNode* node, string value, vector<Ship>& answer) {
    TreeNode* current = node;
    while (current != nullptr) {
        if (value == current->data.ship_name) {
            answer.push_back(current->data);
            current = current->left; // Дубликаты у нас всегда слева, идем дальше
        }
        else if (value < current->data.ship_name) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
}

// ИТЕРАТИВНОЕ УДАЛЕНИЕ (через вектор-стек, чтобы не забить память вызовов)
void delete_bin_tree(TreeNode* root) {
    if (root == nullptr) return;
    
    vector<TreeNode*> stack;
    stack.push_back(root);
    
    while (!stack.empty()) {
        TreeNode* current = stack.back();
        stack.pop_back();
        
        if (current->left != nullptr) stack.push_back(current->left);
        if (current->right != nullptr) stack.push_back(current->right);
        
        delete current;
    }
}