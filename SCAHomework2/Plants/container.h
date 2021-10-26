//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_CONTAINER_H
#define SCAHOMEWORK2_CONTAINER_H
//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер.
//------------------------------------------------------------------------------
#include "plant.h"
#include "tree.h"
#include "flower.h"
#include "shrub.h"
//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива указателей.
class Container {
private:
    // Длина.
    int length;
    // Динамический массив данных.
    Plant **data;
public:
    // Инициализация контейнера.
    void Init(int *size);
    // Очистка контейнера от элементов (отчистка памяти).
    void Clear();
    // Ввод содержимого контейнера из указанного потока.
    void In(FILE *file, const int *size);
    // Случайный ввод содержимого контейнера.
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный файл.
    void Out(FILE *file);
    // Сортировка.
    void HeapSort();
    // Определяем индексы.
    void Heapify(int x, int y);
};


#endif //SCAHOMEWORK2_CONTAINER_H
