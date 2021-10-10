//
// Created by Иван Доронин on 08.10.2021.
//

#include "../Files-with-h/shrub.h"

// Ввод параметров кустарника.
void in(shrub &someShrub, std::ifstream &inputFStream) {
    int month;
    inputFStream >> someShrub.name >> month;
    someShrub.floweringMonthOfShrubs = (shrub::month)month;
}

// Случайное заполнение параметров кустарника.
void inRnd(shrub &someShrub) {
    someShrub.floweringMonthOfShrubs = (shrub::month)randomParam(12);
    randomName(someShrub.name, sizeName);
}

// Вывод параметров кустарника в форматируемый поток.
void out(shrub &someShrub, std::ofstream &outFStream) {
    outFStream << "It is Shrub: name = " << someShrub.name <<
               ", month (JANUARY = 0,\n"
               "        FEBRUARY = 1,\n"
               "        MARCH = 2,\n"
               "        APRIL = 3,\n"
               "        MAY = 4,\n"
               "        JULE = 5,\n"
               "        JULY = 6,\n"
               "        AUGUST = 7,\n"
               "        SEPTEMBER = 8,\n"
               "        OCTOBER = 9,\n"
               "        NOVEMBER = 10,\n"
               "        DECEMBER = 11): " << static_cast<int>(someShrub.floweringMonthOfShrubs);
}

// Параматр для сравнения.
double comparisonParameter(shrub &someShrub) {
    int vowelLettersCount = 0;
    for ( int i = 0; i < sizeName; ++i ) {
        if (someShrub.name[i] == 'a' || someShrub.name[i] == 'e' || someShrub.name[i] == 'i' ||
            someShrub.name[i] == 'o' || someShrub.name[i] == 'u' || someShrub.name[i] == 'y' ||
            someShrub.name[i] == 'A' || someShrub.name[i] == 'E' || someShrub.name[i] == 'I' ||
            someShrub.name[i] == 'O' || someShrub.name[i] == 'U' || someShrub.name[i] == 'Y') {
            vowelLettersCount++;
        }
    }
    return vowelLettersCount / (double)sizeName;
}