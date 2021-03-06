//
// Created by Иван Доронин on 23.10.2021.
//

#ifndef SCAHOMEWORK2_RND_H
#define SCAHOMEWORK2_RND_H
//------------------------------------------------------------------------------
// rnd.h - содержит описание рандомного генератора и его интерфейса.
//------------------------------------------------------------------------------
#include <string>

// Генерация рандомного числа.
inline double RandNumber(int item) {
    return rand() % item;
}
// Генерация рандомного имени.
inline void RandName(char *content, int size) {
    content[0] = toupper(char('a' + rand() % 26));
    for (int i = 1; i < size; ++i) {
        content[i] = char('a' + rand() % 26);
    }
    content[size] = '\0';
}


#endif //SCAHOMEWORK2_RND_H
