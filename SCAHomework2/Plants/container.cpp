//
// Created by Иван Доронин on 23.10.2021.
//
//------------------------------------------------------------------------------
// container.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------
#include "container.h"
//------------------------------------------------------------------------------
// Очистка контейнера от элементов (отчистка памяти).
void Container::Clear() {
    for (int i = 0; i < length; ++i) {
        delete data[i];
    }
    delete data;
    length = 0;
}
//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока.
void Container::In(FILE *file, const int *size) {
    int result, plant_type;
    while(length < *size) {
        result = 1;
        if (fscanf(file, "%d", &plant_type) == EOF) {
            return;
        }
        switch(plant_type) {
            case 1:
                data[length] = new Tree();
                break;
            case 2:
                data[length] = new Flower();
                break;
            case 3:
                data[length] = new Shrub();
                break;
            default:
                result = 0;
        }
        result = (result) ? data[length]->In(file) : 0;

        if (result == 1) {
            length++;
        }
        else if (result == 2) {
            return;
        } else {
            delete data[length];
        }
    }
}
//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера.
void Container::InRnd(int size) {
    printf("Start random filling: \n");
    while(length < size) {
        switch (rand() % 3) {
            case 0:
                data[length] = new Tree();
                break;
            case 1:
                data[length] = new Flower();
                break;
            case 2:
                data[length] = new Shrub();
                break;
        }
        data[length++]->InRnd();
    }
    printf("End random filling.\n");
}
//------------------------------------------------------------------------------
// Инициализация контейнера.
void Container::Init(int *size) {
    printf("Start init: \n");
    data = new Plant*[*size];
    length = 0;
    printf("End init\n");
}
//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный файл.
void Container::Out(FILE *fp) {
    fprintf(fp, "Container contains %d elements.\n", length);
    for(int i = 0; i < length; i++) {
        fprintf(fp, "%d: ", i);
        data[i]->Out(fp);
    }
}
//------------------------------------------------------------------------------
// Меняем местами элементы.
template<typename T>
void swap(T &a, T &b) {
    T temp(std::move(a));
    a = std::move(b);
    b = std::move(temp);
}
// Определяем индексы.
void Container::Heapify(int x, int y) {
    int largest = y;
    int l = 2 * y + 1;
    int r = 2 * y + 2;

    if (l < x && data[l]->ComparisonParam() > data[largest]->ComparisonParam())largest = l;
    if (r < x && data[r]->ComparisonParam() > data[largest]->ComparisonParam())largest = r;

    if (largest != y) {
        swap(data[y], data[largest]);
        Heapify(x, largest);
    }
}
// Сортировка.
void Container::HeapSort() {
    printf("Start heap sorting: \n");
    int n = length;
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(data[0], data[i]);
        Heapify(i, 0);
    }
    printf("End heap sorting.\n");
}