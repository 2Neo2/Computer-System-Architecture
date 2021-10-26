//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_PLANT_H
#define SCAHOMEWORK2_PLANT_H
//------------------------------------------------------------------------------
// plant.h - содержит описание обобщённого растения и его интерфейса
//------------------------------------------------------------------------------
#include <cstdio>
#include "rnd.h"

// Обобщенное расстение.
class Plant {
public:
    // Вывод параметров обобщённого растения в файл.
    virtual bool Out(FILE *file) = 0;
    // Ввод параметров обобщённого растения из файла.
    virtual int In(FILE *fp) = 0;
    // Ввод случайных параметров обобщённого растения.
    virtual bool InRnd() = 0;
    // Подсчет сравнительного параметра.
    virtual double ComparisonParam() = 0;
};


#endif //SCAHOMEWORK2_PLANT_H
