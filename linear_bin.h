#ifndef LINEAR_BIN
#define LINEAR_BIN

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

void search_linear(std::vector<Ship>& my_vector, int n, std::string value, std::vector<Ship>& answer);
TreeNode* create_bin_tree(TreeNode* node, Ship value);
void delete_bin_tree(TreeNode* node);
void search_bin_tree(TreeNode* node, std::string value, std::vector<Ship>& answer);

#endif