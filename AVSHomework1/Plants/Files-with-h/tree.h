//
// Created by Иван Доронин on 08.10.2021.
//

#ifndef AVSHOMEWORK1_TREE_H
#define AVSHOMEWORK1_TREE_H
#include <fstream>
#include "constants.h"
#include "randomGenerator.h"
struct tree {
    char name[sizeName];
    double age;
};

// Ввод параметров дерева из файла.
void in(tree &someTree, std::ifstream &inputFStream);

// Случайный ввод параметров дерева.
void inRnd(tree &someTree);

// Вывод параметров дерева в форматируемый поток.
void out(tree &someTree, std::ofstream &outFStream);

// Частное от деления числа гласных букв в названии на общую длину названия.
double comparisonParameter(tree &someTree);

#endif //AVSHOMEWORK1_TREE_H
