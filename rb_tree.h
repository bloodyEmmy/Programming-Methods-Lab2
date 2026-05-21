#ifndef RB_TREE
#define RB_TREE

#include "structure_generate.h"
#include <string>
#include <vector>

/**
 * @brief Узел красно-черного дерева.
 */
struct RBNode {
    Ship data;               ///< Данные узла (корабль)
    RBNode* left;            ///< Указатель на левого потомка
    RBNode* right;           ///< Указатель на правого потомка
    RBNode* parent;          ///< Указатель на родителя
    bool is_red;             ///< Флаг цвета узла (true - красный, false - черный)

    RBNode(Ship s) {
        data = s;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        is_red = true;
    }
};

/**
 * @brief Добавление нового элемента в красно-черное дерево.
 * @param root Ссылка на корень дерева
 * @param value Данные для добавления
 */
void create_rb_tree(RBNode*& root, Ship value);

/**
 * @brief Левый поворот поддерева относительно указанного узла.
 * @param root Ссылка на корень дерева
 * @param node Узел, вокруг которого выполняется поворот
 */
void left_rotate(RBNode*& root, RBNode* node);

/**
 * @brief Правый поворот поддерева относительно указанного узла.
 * @param root Ссылка на корень дерева
 * @param node Узел, вокруг которого выполняется поворот
 */
void right_rotate(RBNode*& root, RBNode* node);

/**
 * @brief Восстановление баланса красно-черного дерева после вставки.
 * @param root Ссылка на корень дерева
 * @param node Недавно добавленный узел
 */
void fix_rb_tree(RBNode*& root, RBNode* node);

/**
 * @brief Поиск элементов в красно-черном дереве.
 * @param node Корень дерева
 * @param value Искомое имя корабля
 * @param answer Вектор для сохранения результатов
 */
void search_rb_tree(RBNode* node, std::string value, std::vector<Ship>& answer);

/**
 * @brief Итеративное удаление всего красно-черного дерева и освобождение памяти.
 * @param node Корень дерева
 */
void delete_rb_tree(RBNode* node);

#endif