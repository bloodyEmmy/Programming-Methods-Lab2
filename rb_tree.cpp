#include "rb_tree.h"

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
    
    fix_rb_tree(root, new_node);
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

void right_rotate(RBNode*& root, RBNode* node) {
    RBNode* new_top = node->left;
    node->left = new_top->right;

    if (new_top->right != nullptr) {
        new_top->right->parent = node;
    }
    new_top->parent = node->parent;
    if (node->parent == nullptr) {
        root = new_top;
    }
    else if (node->parent->right == node) {
        node->parent->right = new_top;
    }
    else {
        node->parent->left = new_top;
    }
    new_top->right = node;
    node->parent = new_top;
}

void fix_rb_tree(RBNode*& root, RBNode* node) {
    while (node->parent != nullptr && node->parent->is_red == true) {
        RBNode* grandparent = node->parent->parent;

        if (node->parent == grandparent->left) {
            RBNode* uncle = grandparent->right;

            if (uncle != nullptr && uncle->is_red == true) {
                node->parent->is_red = false;
                uncle->is_red = false;
                grandparent->is_red = true;
                node = grandparent;
            }
            else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(root, node);
                }
                node->parent->is_red = false;
                grandparent->is_red = true;
                right_rotate(root, grandparent);
            }
        }
        else {
            RBNode* uncle = grandparent->left;

            if (uncle != nullptr && uncle->is_red == true) {
                node->parent->is_red = false;
                uncle->is_red = false;
                grandparent->is_red = true;
                node = grandparent;
            }
            else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(root, node);
                }
                node->parent->is_red = false;
                grandparent->is_red = true;
                left_rotate(root, grandparent);
            }
        }
    }
    root->is_red = false;
}

void search_rb_tree(RBNode* node, string value, vector<Ship>& answer) {
    if (node == nullptr) {
        return;
    }
    else {
        if (value == node->data.ship_name) {
            answer.push_back(node->data);
            search_rb_tree(node->left, value, answer);
            search_rb_tree(node->right, value, answer);
        }
        else if (value < node->data.ship_name) {
            search_rb_tree(node->left, value, answer);
        }
        else {
            search_rb_tree(node->right, value, answer);
        }
    }
}

void delete_rb_tree(RBNode* node) {
    if (node == nullptr) {
        return;
    }
    else {
        delete_rb_tree(node->left);
        delete_rb_tree(node->right);
        delete node;
    }
}