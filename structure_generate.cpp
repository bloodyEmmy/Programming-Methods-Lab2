#include "structure_generate.h"

using namespace std;

void generate_vector(vector<Ship>& my_vector) {
    string arr_ship_name[] = {"Атлант", "Титан", "Монарх", "Орион", "Феникс", "Шквал", "Варяг", "Витязь",
        "Тайфун", "Мираж", "Левиафан", "Авангард"};
    string arr_ship_country[] = {"США", "Китай", "Россия", "Индия", "Япония", "Великобритания", "Франция", "Италия"};
    string arr_ship_type[] = {"Танкер", "Сухогруз", "Пассажирский"};
    string arr_captain_name[] = {"Александр", "Максим", "Артем", "Дмитрий", "Марк", "Лев", "Виктор", "Роман", "Игорь"};
    string arr_captain_surname[] = {"Волков", "Белов", "Морозов", "Орлов", "Громов", "Лебедев", "Соколов"};
    string arr_captain_patronymic[] = {"Александрович", "Викторович", "Сергеевич", "Андреевич", "Дмитриевич"};
    
    for (int i = 0; i < 1000000; i++) {
        my_vector[i].ship_name = arr_ship_name[rand() % size(arr_ship_name)];
        my_vector[i].year_build = (1900 + rand() % 127);
        my_vector[i].country_build = arr_ship_country[rand() % size(arr_ship_country)];
        my_vector[i].ship_type = arr_ship_type[rand() % size(arr_ship_type)];
        
        string captain = arr_captain_surname[rand() % size(arr_captain_surname)] + " " +
            arr_captain_name[rand() % size(arr_captain_name)] + " " +
            arr_captain_patronymic[rand() % size(arr_captain_patronymic)];
        my_vector[i].captain_name = captain;
    }
}