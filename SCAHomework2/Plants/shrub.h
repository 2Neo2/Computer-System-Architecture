//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_SHRUB_H
#define SCAHOMEWORK2_SHRUB_H
//------------------------------------------------------------------------------
// shrub.h - содержит описание кустарника и его интерфейса.
//------------------------------------------------------------------------------
#include <cstdio>
#include "plant.h"
#include "rnd.h"

// Кустарник.
class Shrub: public Plant {
private:
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
    // Имя.
    char name[10];
    // Месяц цветения.
    month floweringMonthOfShrubs;
public:
    // Вывод параметров кустарника в файл.
    bool Out(FILE *file) override;
    // Ввод параметров кустарника из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров кустарника.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};


#endif //SCAHOMEWORK2_SHRUB_H
