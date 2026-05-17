#ifndef SEARCH_H
#define SEARCH_H

#include "structure_generate.h"

struct TreeNode {
    Ship data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Ship s) {
        data = s;
        left = nullptr;
        right = nullptr;
    }
};

std::vector<Ship> search_linear(std::vector<Ship>& my_vector, int n, std::string value);
TreeNode* create_bin_tree(TreeNode* node, Ship value);

#endif