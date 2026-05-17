#ifndef STRUCTURE_GENERATE_H
#define STRUCTURE_GENERATE_H

#include <string>
#include <vector>
#include <ctime>

struct Ship {
    std::string ship_name;
    int year_build;
    std::string country_build;
    std::string ship_type;
    std::string captain_name;
};

void generate_vector(std::vector<Ship>& my_vector);

#endif 