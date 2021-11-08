# ------------------------------------------------------------------------------
# tree.py - description tree functions.
# ------------------------------------------------------------------------------
import random
from random import choice
from string import ascii_letters


# ------------------------------------------------------------------------------
# Filling tree objects with values from file.
def in_from_file(tree_arr, command):
    str_arr = command.split(' ')
    tree_arr.append("Tree")
    tree_arr.append(str_arr[2])
    tree_arr.append(float(str_arr[1]))
    tree_arr.append(comparison_param(tree_arr))


# ------------------------------------------------------------------------------
# Filling tree objects to random values.
def in_rnd(tree_arr):
    tree_arr.append("Tree")
    tree_arr.append(''.join(choice(ascii_letters) for i in range(12)))
    tree_arr.append(random.randint(1, 1000))
    tree_arr.append(comparison_param(tree_arr))


# ------------------------------------------------------------------------------
# Comparison parameter for heap sort.
def comparison_param(tree_arr):
    vowel_letters_count = 0
    name = tree_arr[1]
    for i in name:
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u' or i == 'y' or i == 'A' or i == 'E' or i == 'I' or i == 'O' or i == 'U' or i == 'Y':
            vowel_letters_count += 1
    return vowel_letters_count / float(len(name))
