//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_FLOWER_H
#define SCAHOMEWORK2_FLOWER_H
//------------------------------------------------------------------------------
// flower.h - содержит описание цветка и его интерфейса
//------------------------------------------------------------------------------
#include <cstdio>
#include "plant.h"
#include "rnd.h"

// Цветок.
class Flower : public Plant {
private:
    enum type {
        DOMESTIC = 0,
        GARDEN = 1,
        WILD = 2,
        ARTIFICIAL = 3
    };
    // Имя.
    char name[10];
    // Тип цветка.
    type typeFlower;
public:
    // Вывод параметров цветка в файл.
    bool Out(FILE *file) override;
    // Ввод параметров цветка из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров цветка.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};


#endif //SCAHOMEWORK2_FLOWER_H
