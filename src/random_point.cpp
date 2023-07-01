#include "my.h"

float get_random_value()
{
    const int range_from  = -10;
    const int range_to    = 10;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    float final_nbr = (float)distr(generator) / 10;
    return final_nbr;
}

int random_range_int(int range_min, int range_max)
{
    const int range_from  = range_min;
    const int range_to    = range_max;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);
    int final_nbr = (int)distr(generator);
    return final_nbr;
}

bool randomBool()
{
   return rand() > (RAND_MAX / 2);
}

void set_seed_point(float point[2], int x, int z)
{
    /*int plus_or_min = ((x + z) * (x + z)) * (seed * seed);
    std::cout << plus_or_min << std::endl;
    if (plus_or_min % 10 > 4) {
        point[0] = (((x + z) * (x + z)) * seed) % 10;
    } else {
        point[0] = -((((x + z) * (x + z)) * seed) % 10);
    }
    plus_or_min = ((x - z * 2) * (x - z * 2)) * (seed * seed);
    if (plus_or_min % 10 > 4) {
        point[1] = (((x - z * 2) * (x - z * 2)) * seed) % 10;
    } else {
        point[1] = -((((x - z * 2) * (x - z * 2)) * seed) % 10);
    }
    std::cout << point[0] << std::endl;
    std::cout << point[1] << std::endl;*/
    float nbr1 = get_random_value();
    point[0] = nbr1;
    float nbr2 = get_random_value();
    point[1] = nbr2;
}