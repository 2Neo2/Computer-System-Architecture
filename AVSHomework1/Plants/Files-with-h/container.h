//
// Created by Иван Доронин on 08.10.2021.
//

#ifndef AVSHOMEWORK1_CONTAINER_H
#define AVSHOMEWORK1_CONTAINER_H
#include <fstream>
#include "plant.h"

struct container {
    enum {
        max_len = 10000
    };

    int length;
    plant *data[max_len];
};

// Инициализация контейнера.
void init(container &container);

// Очистка контейнера от элементов (освобождение памяти).
void clear(container &container);

// Ввод содержимого контейнера из указанного потока.
void in(container &container, std::ifstream &inputFStream);

// Случайный ввод содержимого контейнера.
void inRnd(container &container, int size);

// Вывод содержимого контейнера в указанный поток.
void out(container &container, std::ofstream &outFStream);

// Метод для перемещения ссылок.
void swap(plant *a, plant *b);

// Частное от деления числа гласных букв в названии на общую длину названия.
void heapSort(container &container, int n);

#endif //AVSHOMEWORK1_CONTAINER_H
