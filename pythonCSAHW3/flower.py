# ------------------------------------------------------------------------------
# flower.py - Container handling functions.
# ------------------------------------------------------------------------------
import random
from random import choice
from string import ascii_letters


# ------------------------------------------------------------------------------
# Filling flower objects with values from file.
def in_from_file(flower_arr, command):
    str_arr = command.split(' ')
    flower_arr.append("Flower")
    flower_arr.append(str_arr[2])
    type_of_flower = float(str_arr[1]) % 4
    if type_of_flower == 0:
        flower_arr.append("JANUARY")
    elif type_of_flower == 1:
        flower_arr.append("FEBRUARY")
    elif type_of_flower == 2:
        flower_arr.append("MARCH")
    elif type_of_flower == 3:
        flower_arr.append("APRIL")
    flower_arr.append(comparison_param(flower_arr))


# ------------------------------------------------------------------------------
# Filling flower objects to random values.
def in_rnd(flower_arr):
    flower_arr.append("Flower")
    flower_arr.append(''.join(choice(ascii_letters) for i in range(12)))
    type_of_flower = random.randint(0, 3)
    if type_of_flower == 0:
        flower_arr.append("JANUARY")
    elif type_of_flower == 1:
        flower_arr.append("FEBRUARY")
    elif type_of_flower == 2:
        flower_arr.append("MARCH")
    elif type_of_flower == 3:
        flower_arr.append("APRIL")
    flower_arr.append(comparison_param(flower_arr))


# ------------------------------------------------------------------------------
# Comparison parameter for heap sort.
def comparison_param(flower_arr):
    vowel_letters_count = 0
    name = flower_arr[1]
    for i in name:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'y' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or i == 'Y':
            vowel_letters_count += 1
    return vowel_letters_count / float(len(name))