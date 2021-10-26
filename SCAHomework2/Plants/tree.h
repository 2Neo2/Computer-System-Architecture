//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_TREE_H
#define SCAHOMEWORK2_TREE_H
//------------------------------------------------------------------------------
// tree.h - содержит описание дерева и его интерфейса.
//------------------------------------------------------------------------------
#include <cstdio>
#include "plant.h"
#include "rnd.h"

// Дерево.
class Tree : public Plant {
private:
    // Имя.
    char name[10];
    // Взраст дерева.
    double age;
public:
    // Вывод параметров дерева в файл.
    bool Out(FILE *file) override;
    // Ввод параметров дерева из файла.
    int In(FILE *file) override;
    // Ввод случайных параметров дерева.
    bool InRnd() override;
    // Подсчет сравнительного параметра.
    double ComparisonParam() override;
};


#endif //SCAHOMEWORK2_TREE_H
