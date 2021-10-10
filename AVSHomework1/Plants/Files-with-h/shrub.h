//
// Created by Иван Доронин on 08.10.2021.
//

#ifndef AVSHOMEWORK1_SHRUB_H
#define AVSHOMEWORK1_SHRUB_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"

struct shrub {
    enum month {
        JANUARY = 0,
        FEBRUARY = 1,
        MARCH = 2,
        APRIL = 3,
        MAY = 4,
        JULE = 5,
        JULY = 6,
        AUGUST = 7,
        SEPTEMBER = 8,
        OCTOBER = 9,
        NOVEMBER = 10,
        DECEMBER = 11
    };
    char name[sizeName];
    month floweringMonthOfShrubs;
};

// Ввод параметров кустарника из файла.
void in(shrub &someShrub, std::ifstream &inputFStream);

// Случайный ввод параметров кустарника.
void inRnd(shrub &someShrub);

// Вывод параметров кустарника в форматируемый поток.
void out(shrub &someShrub, std::ofstream &outFStream);

// Частное от деления числа гласных букв в названии на общую длину названия.
double comparisonParameter(shrub &someShrub);;


#endif //AVSHOMEWORK1_SHRUB_H
