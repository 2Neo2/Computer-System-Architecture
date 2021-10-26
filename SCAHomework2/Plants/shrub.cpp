//
// Created by Иван Доронин on 23.10.2021.
//
//------------------------------------------------------------------------------
// shrub.cpp - содержит функции обработки кустарника.
//------------------------------------------------------------------------------
#include "shrub.h"
#include <cstring>
//------------------------------------------------------------------------------
// Вывод параметров кустарника в файл.
bool Shrub::Out(FILE *file) {
    fprintf(file, "It is Shrub:\n"
                 "-name: %s,\n"
                 "-month of flowering: %d,\n"
                 "-function result: %lf\n\n", name, (int)floweringMonthOfShrubs, ComparisonParam());
    return true;
}
//------------------------------------------------------------------------------
// Ввод случайных параметров кустарника.
bool Shrub::InRnd() {
    RandName(name, 10);
    floweringMonthOfShrubs = (month)RandNumber(12);
    return true;
}
//------------------------------------------------------------------------------
// Ввод параметров кустарника из файла.
int Shrub::In(FILE *file) {
    char buffer1[100], buffer2[10];
    int number = 0;
    if (fscanf(file, "%s%s", buffer1, buffer2) == EOF) {
        return 2;
    }
    if ((((number = atoi(buffer1)) < 0) || ((number = atoi(buffer1)) > 11))){
        return 0;
    }
    floweringMonthOfShrubs = (month)number;
    strcpy (name, buffer2);
    return 1;
}
//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Shrub::ComparisonParam() {
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