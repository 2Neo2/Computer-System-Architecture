//
// Created by Иван Доронин on 08.10.2021.
//

#ifndef AVSHOMEWORK1_PLANT_H
#define AVSHOMEWORK1_PLANT_H
#include "tree.h"
#include "flower.h"
#include "shrub.h"

struct plant{
    enum key {
        TREE = 0,
        FLOWER = 1,
        SHRUB = 2
    };
    union {
        flower someFlower;
        shrub someShrub;
        tree someTree;
    };
    key typeOfPlant;
};

// Ввод обобщения растения.
plant *in(std::ifstream &inputFStream);

// Случайный ввод обобщения растения.
plant *inRnd();

// Вывод обобщения растения.
void out(plant &somePlant, std::ofstream &outFStream);

// Параметр сортировки.
double comparisonParameter(plant &somePlant);

#endif //AVSHOMEWORK1_PLANT_H
