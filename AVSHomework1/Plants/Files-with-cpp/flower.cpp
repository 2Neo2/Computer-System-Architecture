//
// Created by Иван Доронин on 08.10.2021.
//
#include "../Files-with-h/flower.h"

// Ввод параметров цветов из файла.
void in(flower &someFlower, std::ifstream &inputFStream) {
    int type;
    inputFStream >> someFlower.name >> type;
    someFlower.typeFlower = (flower::type)type;
}

// Случайный ввод параметров цветов.
void inRnd(flower &someFlower) {
    someFlower.typeFlower = (flower::type)randomParam(4);
    randomName(someFlower.name, sizeName);
}

// Вывод параметров цветов в форматируемый поток.
void out(flower &someFlower, std::ofstream &outFStream) {
    outFStream << "It is FLower: name = " << someFlower.name <<
               ", type of flower (DOMESTIC = 0,\n"
               "        GARDEN = 1,\n"
               "        WILD = 2,\n"
               "        ARTIFICIAL = 3): " << static_cast<int>(someFlower.typeFlower);
}

// Частное от деления числа гласных букв в названии на общую длину названия.
double comparisonParameter(flower &someFlower) {
    int vowelLettersCount = 0;
    for ( int i = 0; i < sizeName; ++i ) {
        if (someFlower.name[i] == 'a' || someFlower.name[i] == 'e' || someFlower.name[i] == 'i' ||
            someFlower.name[i] == 'o' || someFlower.name[i] == 'u' || someFlower.name[i] == 'y' ||
            someFlower.name[i] == 'A' || someFlower.name[i] == 'E' || someFlower.name[i] == 'I' ||
            someFlower.name[i] == 'O' || someFlower.name[i] == 'U' || someFlower.name[i] == 'Y') {
            vowelLettersCount++;
        }
    }
    return vowelLettersCount / (double)sizeName;
}

