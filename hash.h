#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>

#include "structure_generate.h"
void full_array(std::vector<std::vector<Ship>>& vector_array, std::vector<Ship>& fleet, int s);
void find_ship(std::vector<std::vector<Ship>>& vector_array, std::string name, std::vector<Ship>& answer);

#endif