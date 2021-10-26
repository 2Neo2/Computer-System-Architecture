//
// Created by Иван Доронин on 23.10.2021.
//
//------------------------------------------------------------------------------
// flower.cpp - содержит функции обработки цветка.
//------------------------------------------------------------------------------
#include "flower.h"
#include <cstring>
//------------------------------------------------------------------------------
// Вывод параметров цветка в файл.
bool Flower::Out(FILE *file) {
    fprintf(file, "It is Flower:\n"
                  "-name: %s,\n"
                  "-type of flower: %d,\n"
                  "-function result: %lf\n\n", name, (int)typeFlower, ComparisonParam());
    return true;
}
//------------------------------------------------------------------------------
// Ввод случайных параметров цветка.
bool Flower::InRnd() {
    RandName(name, 10);
    typeFlower = (type)RandNumber(4);
    return true;
}
//------------------------------------------------------------------------------
// Ввод параметров цветка из файла.
int Flower::In(FILE *file) {
    char buffer1[100], buffer2[10];
    int number = 0;
    if (fscanf(file, "%s%s", buffer1, buffer2) == EOF) {
        return 2;
    }
    if ((((number = atoi(buffer1)) < 0) || ((number = atoi(buffer1)) > 11))){
        return 0;
    }
    typeFlower = (type)number;
    strcpy (name, buffer2);
    return 1;
}
//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Flower::ComparisonParam() {
    int vowelLettersCount = 0;
    int size = 10;
    for ( int i = 0; i < size; ++i ) {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' ||
            name[i] == 'o' || name[i] == 'u' || name[i] == 'y' ||
            name[i] == 'A' || name[i] == 'E' || name[i] == 'I' ||
            name[i] == 'O' || name[i] == 'U' || name[i] == 'Y') {
            vowelLettersCount++;
        }
    }
    return vowelLettersCount / (double)size;
}