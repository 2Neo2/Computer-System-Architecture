//
// Created by Иван Доронин on 08.10.2021.
//

#include "../Files-with-h/tree.h"

// Ввод параметров дерева.
void in(tree &someTree, std::ifstream &inputFStream) {
    inputFStream >> someTree.name >> someTree.age;
}

// Случайное заполнение параметров дерева.
void inRnd(tree &someTree) {
    someTree.age = randomParam(1000);
    randomName(someTree.name, sizeName);
}

// Вывод параметров дерева в форматируемый поток.
void out(tree &someTree, std::ofstream &outFStream) {
    outFStream << "It is Tree: name = " << someTree.name <<
         ", age = " << someTree.age;
}

// Параматр для сравнения.
double comparisonParameter(tree &someTree) {
    int vowelLettersCount = 0;
    for ( int i = 0; i < sizeName; ++i ) {
        if (someTree.name[i] == 'a' || someTree.name[i] == 'e' || someTree.name[i] == 'i' ||
        someTree.name[i] == 'o' || someTree.name[i] == 'u' || someTree.name[i] == 'y' ||
        someTree.name[i] == 'A' || someTree.name[i] == 'E' || someTree.name[i] == 'I' ||
        someTree.name[i] == 'O' || someTree.name[i] == 'U' || someTree.name[i] == 'Y') {
            vowelLettersCount++;
        }
    }
    return vowelLettersCount / (double)sizeName;
}