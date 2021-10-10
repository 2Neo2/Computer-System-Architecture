//
// Created by Иван Доронин on 08.10.2021.
//

#ifndef AVSHOMEWORK1_FLOWER_H
#define AVSHOMEWORK1_FLOWER_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"

struct flower {
    enum type {
        DOMESTIC = 0,
        GARDEN = 1,
        WILD = 2,
        ARTIFICIAL = 3
    };
    char name[sizeName];
    type typeFlower;
};

// Ввод параметров цветов из файла.
void in(flower &someFlower, std::ifstream &inputFStream);

// Случайный ввод параметров цветов.
void inRnd(flower &someFlower);

// Вывод параметров цветов в форматируемый поток.
void out(flower &someFlower, std::ofstream &outFStream);

// Частное от деления числа гласных букв в названии на общую длину названия.
double comparisonParameter(flower &someFlower);

#endif //AVSHOMEWORK1_FLOWER_H
