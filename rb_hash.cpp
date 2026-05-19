#include "rb_hash.h"

using namespace std;

void create_rb_tree(RBNode*& root, Ship value) {
    RBNode* new_node = new RBNode(value);
    RBNode* parent = nullptr;
    RBNode* current = root;

    while (current != nullptr) {
        parent = current;
        if (new_node->data.ship_name <= current->data.ship_name) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    new_node->parent = parent;
    if (parent == nullptr) {
        root = new_node;
    }
    else if (new_node->data.ship_name <= parent->data.ship_name) {
        parent->left = new_node;
    }
    else {
        parent->right = new_node;
    }
}

void left_rotate(RBNode*& root, RBNode* node) {
    RBNode* new_top = node->right;
    node->right = new_top->left;

    if (new_top->left != nullptr) {
        new_top->left->parent = node;
    }
    new_top->parent = node->parent;
    if (node->parent == nullptr) {
        root = new_top;
    }
    else if (node->parent->left == node) {
        node->parent->left = new_top;
    }
    else {
        node->parent->right = new_top;
    }
    new_top->left = node;
    node->parent = new_top;
}