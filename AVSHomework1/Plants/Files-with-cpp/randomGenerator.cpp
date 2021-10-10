//
// Created by Иван Доронин on 08.10.2021.
//

#include <cctype>
#include "../Files-with-h/randomGenerator.h"

// Генерация рандомного числа.
int randomParam(int item) {
    return std::rand() % item;
}

// Генерация рандомного имени.
void randomName(char *content, int size) {
    content[0] = toupper(char('a' + std::rand() % 26));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + std::rand() % 26);
    }
    content[size] = '\0';
}