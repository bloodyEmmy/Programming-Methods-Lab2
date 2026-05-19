#ifndef RB_TREE
#define RB_TREE

#include "structure_generate.h"
#include <string>
#include <vector>

struct RBNode {
    Ship data;
    RBNode* left;
    RBNode* right;
    RBNode* parent;
    bool is_red;

    RBNode(Ship s) {
        data = s;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        is_red = true;
    }
};

void create_rb_tree(RBNode*& root, Ship value);
void left_rotate(RBNode*& root, RBNode* node);
void right_rotate(RBNode*& root, RBNode* node);
void fix_rb_tree(RBNode*& root, RBNode* node);
void search_rb_tree(RBNode* node, std::string value, std::vector<Ship>& answer);
void delete_rb_tree(RBNode* node);

#endif