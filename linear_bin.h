#ifndef LINEAR_BIN
#define LINEAR_BIN

#include "structure_generate.h"

/**
 * @brief Узел обычного бинарного дерева поиска.
 */
struct TreeNode {
    Ship data;               ///< Данные узла (корабль)
    TreeNode* left;          ///< Указатель на левого потомка
    TreeNode* right;         ///< Указатель на правого потомка

    TreeNode(Ship s) {
        data = s;
        left = nullptr;
        right = nullptr;
    }
};

/**
 * @brief Последовательный поиск элементов в векторе.
 * @param my_vector Исходный вектор с данными
 * @param n Количество просматриваемых элементов
 * @param value Искомое имя корабля
 * @param answer Вектор для сохранения результатов
 */
void search_linear(std::vector<Ship>& my_vector, int n, std::string value, std::vector<Ship>& answer);

/**
 * @brief Итеративное добавление нового элемента в бинарное дерево.
 * @param root Корень дерева
 * @param value Данные для добавления
 * @return Обновленный корень дерева
 */
TreeNode* create_bin_tree(TreeNode* root, Ship value);

/**
 * @brief Итеративное удаление всего бинарного дерева и освобождение памяти.
 * @param node Корень дерева
 */
void delete_bin_tree(TreeNode* node);

/**
 * @brief Итеративный поиск элементов в бинарном дереве.
 * @param node Корень дерева
 * @param value Искомое имя корабля
 * @param answer Вектор для сохранения результатов
 */
void search_bin_tree(TreeNode* node, std::string value, std::vector<Ship>& answer);

#endif