//
// Created by Иван Доронин on 23.10.2021.
//
//------------------------------------------------------------------------------
// tree.cpp - содержит функции обработки дерева.
//------------------------------------------------------------------------------
#include "tree.h"
#include <cstring>
//------------------------------------------------------------------------------
// Ввод параметров дерева из файла.
int Tree::In(FILE *file) {
    char buffer1[100], buffer2[10];
    if (fscanf(file, "%s%s", buffer1, buffer2) == EOF) {
        return 2;
    }
    if (((age = atof(buffer1)) == 0) && (strcmp(buffer1, "0") != 0)){
        return 0;
    }
    strcpy (name, buffer2);
    return 1;
}
//------------------------------------------------------------------------------
// Ввод случайных параметров дерева.
bool Tree::InRnd() {
    RandName(name, 10);
    age = RandNumber(1000);
    return true;
}
//------------------------------------------------------------------------------
// Вывод параметров дерева в файл.
bool Tree::Out(FILE *file) {
    fprintf(file, "It is Tree:\n"
                  "-name: %s,\n"
                  "-age: %f,\n"
                  "-function result: %lf\n\n", name, age, ComparisonParam());
    return true;
}
//------------------------------------------------------------------------------
// Подсчет сравнительного параметра.
double Tree::ComparisonParam() {
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