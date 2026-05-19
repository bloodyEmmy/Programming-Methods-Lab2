#ifndef RB_HASH
#define RB_HASH

#include "structure_generate.h"
#include <string>

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

void create_rb_tree(RBNode* root, Ship value);
void left_rotate(RBNode* root, RBNode* node);

#endif