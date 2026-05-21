#ifndef STRUCTURE_GENERATE_H
#define STRUCTURE_GENERATE_H

#include <string>
#include <vector>
#include <ctime>

/**
 * @brief Структура, содержащая информацию о корабле.
 */
struct Ship {
    std::string ship_name;     ///< Название корабля
    int year_build;            ///< Год постройки
    std::string country_build; ///< Страна постройки
    std::string ship_type;     ///< Тип судна (танкер, сухогруз и т.д.)
    std::string captain_name;  ///< ФИО капитана
};

/**
 * @brief Генерирует массив случайных кораблей.
 * @param my_vector Ссылка на вектор для заполнения данными
 */
void generate_vector(std::vector<Ship>& my_vector);

#endif