#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include "structure_generate.h"

/**
 * @brief Заполнение хэш-таблицы элементами из вектора.
 * @param vector_array Хэш-таблица (вектор корзин)
 * @param fleet Исходный вектор с данными кораблей
 * @param s Количество элементов для добавления
 */
void full_array(std::vector<std::vector<Ship>>& vector_array, std::vector<Ship>& fleet, int s);

/**
 * @brief Поиск элементов в хэш-таблице по ключу.
 * @param vector_array Хэш-таблица
 * @param name Искомое имя корабля
 * @param answer Вектор для сохранения результатов
 */
void find_ship(std::vector<std::vector<Ship>>& vector_array, std::string name, std::vector<Ship>& answer);

#endif