//
// Created by Иван Доронин on 02.12.2021.
//
#ifndef SCAHW4_PLANT_H
#define SCAHW4_PLANT_H
#include <string.h>
#include <stdlib.h>
#include "stdio.h"
#include "constants.h"
#include "rnd.h"

struct tree {
    int age;
};

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
    } floweringMonthOfShrubs;
};

struct flower {
    enum type {
        DOMESTIC = 0,
        GARDEN = 1,
        WILD = 2,
        ARTIFICIAL = 3
    } type_of_flower;
};

struct plant {
    enum key {
        TREE = 0, SHRUB = 1, FLOWER = 2
    } type_of_plant;
    union {
        struct tree someTree;
        struct shrub someShrub;
        struct flower someFlower;
    };
    char name[NAME_SIZE];
};

struct plant *readPlant(FILE *from_file);

struct plant *fillPlant();

void outPlant(struct plant *plant_, FILE *out_file);

extern double comparisonParameter(struct plant *somePlant);

#endif //SCAHW4_PLANT_H
