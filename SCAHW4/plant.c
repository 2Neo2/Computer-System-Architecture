//
// Created by Иван Доронин on 02.12.2021.
//

#include "header_files/plant.h"

struct plant *readPlant(FILE *from_file) {
    struct plant *plant_;
    char type_of_plant[NAME_SIZE];
    char name[NAME_SIZE];

    fscanf(from_file, "%s\n", type_of_plant);

    if (!strcmp(type_of_plant, "tree")) {
        int age;
        fscanf(from_file, "%s %d \n", name, &age);
        plant_ = malloc(sizeof(struct plant));
        plant_->type_of_plant = TREE;
        plant_->someTree.age = age;
        for (int i = 0; i < NAME_SIZE; ++i) {
            plant_->name[i] = name[i];
        }
        return plant_;
    } else if (!strcmp(type_of_plant, "shrub")) {
        int floweringMonthOfShrubs;
        fscanf(from_file, "%s %d \n", name, &floweringMonthOfShrubs);
        plant_ = malloc(sizeof(struct plant));
        plant_->type_of_plant = SHRUB;
        plant_->someShrub.floweringMonthOfShrubs = floweringMonthOfShrubs % 12 ;
        for (int i = 0; i < NAME_SIZE; ++i) {
            plant_->name[i] = name[i];
        }
        return plant_;
    } else if (!strcmp(type_of_plant, "flower")) {
        int type_of_flower;
        fscanf(from_file, "%s %d \n", name, &type_of_flower);
        plant_ = malloc(sizeof(struct plant));
        plant_->type_of_plant  = FLOWER;
        plant_->someFlower.type_of_flower = type_of_flower % 4;
        for (int i = 0; i < NAME_SIZE; ++i) {
            plant_->name[i] = name[i];
        }
        return plant_;
    } else {
        printf("ERROR: Wrong plant type %s\n", type_of_plant);
        exit(1);
    }
}

struct plant *fillPlant() {
    struct plant *plant_;
    int type_of_plant = rand() % 3;
    switch (type_of_plant) {
        case 0:
            plant_ = malloc(sizeof(struct plant));
            plant_->type_of_plant = TREE;
            plant_->someTree.age = rand();
            randStr(plant_->name, NAME_SIZE);
            return plant_;
        case 1:
            plant_ = malloc(sizeof(struct plant));
            plant_->type_of_plant = SHRUB;
            randStr(plant_->name, NAME_SIZE);
            plant_->someShrub.floweringMonthOfShrubs = (rand() % 12);
            return plant_;
        case 2:
            plant_ = malloc(sizeof(struct plant));
            plant_->type_of_plant = FLOWER;
            randStr(plant_->name, NAME_SIZE);
            plant_->someFlower.type_of_flower = (rand() % 4);
            return plant_;
        default:
            return NULL;
    }
}

void outPlant(struct plant *plant_, FILE *out_file) {
    switch (plant_->type_of_plant) {
        case TREE:
            fprintf(out_file, "[Tree]\n"
                         "-name: %s\n"
                         "-age %d\n"
                         "-comparison parameter: %lf\n\n",
                    plant_->name,
                    plant_->someTree.age,
                    comparisonParameter(plant_));
            break;
        case SHRUB:
            fprintf(out_file, "[Shrub]\n"
                         "-name: %s\n"
                         "-flowering month of shrub %d\n"
                         "-comparison parameter: %lf\n\n",
                    plant_->name,
                    plant_->someShrub.floweringMonthOfShrubs,
                    comparisonParameter(plant_));
            break;
        case FLOWER:
            fprintf(out_file, "[Flower]\n"
                         "-name: %s\n"
                         "-type of flower: %d\n"
                         "-comparison parameter: %lf\n\n",
                    plant_->name,
                    plant_->someFlower.type_of_flower,
                    comparisonParameter(plant_));
            break;
    }
}

double comparisonParameter(struct plant *somePlant) {
    int vowelLettersCount = 0;
    for ( int i = 0; i < NAME_SIZE; ++i ) {
        if (somePlant->name[i] == '\0') {
            break;
        }
        if (somePlant->name[i] == 'a' || somePlant->name[i] == 'e' || somePlant->name[i] == 'i' ||
            somePlant->name[i] == 'o' || somePlant->name[i] == 'u' || somePlant->name[i] == 'y' ||
            somePlant->name[i] == 'A' || somePlant->name[i] == 'E' || somePlant->name[i] == 'I' ||
            somePlant->name[i] == 'O' || somePlant->name[i] == 'U' || somePlant->name[i] == 'Y') {
            vowelLettersCount++;
        }
    }
    return vowelLettersCount / (double) NAME_SIZE;
}