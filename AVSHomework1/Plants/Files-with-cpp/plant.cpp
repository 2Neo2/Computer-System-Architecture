//
// Created by Иван Доронин on 08.10.2021.
//

#include "../Files-with-h/plant.h"
// Метод возвращающий содерживое ошибки.
std::string errMessage1() {
    return "incorrect name of plant:!\n"
           "Waited:\n"
           "TREE = 0,\n"
           "FLOWER = 1,\n"
           "SHRUB = 2\n";
}

// Ввод обобщения растения.
plant *in(std::ifstream &inputFStream) {
    plant *somePlant;
    int typeOfPlant;
    inputFStream >> typeOfPlant;
    switch (typeOfPlant) {
        case 0:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::TREE;
            in(somePlant->someTree, inputFStream);
            return somePlant;
        case 1:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::FLOWER;
            in(somePlant->someFlower, inputFStream);
            return somePlant;
        case 2:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::SHRUB;
            in(somePlant->someShrub, inputFStream);
            return somePlant;
        default:
            return nullptr;
    }
}

// Случайный ввод обобщения растения.
plant *inRnd() {
    plant *somePlant;
    auto typeOfPlant = std::rand() % 3;
    switch (typeOfPlant) {
        case 0:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::TREE;
            inRnd(somePlant->someTree);
            return somePlant;
        case 1:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::FLOWER;
            inRnd(somePlant->someFlower);
            return somePlant;
        case 2:
            somePlant = new plant;
            somePlant->typeOfPlant = plant::SHRUB;
            inRnd(somePlant->someShrub);
            return somePlant;
        default:
            return nullptr;

    }
}

// Вывод обобщения растения.
void out(plant &somePlant, std::ofstream &outFStream) {
    switch (somePlant.typeOfPlant) {
        case plant::FLOWER:
            out(somePlant.someFlower, outFStream);
            break;
        case plant::TREE:
            out(somePlant.someTree, outFStream);
            break;
        case plant::SHRUB:
            out(somePlant.someShrub, outFStream);
            break;
        default:
            outFStream << errMessage1;
    }
    outFStream << "\n";
}

// Параметр сортировки.
double comparisonParameter(plant &somePlant) {
    switch (somePlant.typeOfPlant) {
        case plant::FLOWER:
            return comparisonParameter(somePlant.someFlower);
        case plant::TREE:
            return comparisonParameter(somePlant.someTree);
        case plant::SHRUB:
            return comparisonParameter(somePlant.someShrub);
        default:
            return -1;
    }
}