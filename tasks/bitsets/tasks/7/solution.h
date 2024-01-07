#pragma once

#include <stdint.h>
#include <stdio.h>

typedef uint32_t Bitset;

Bitset Consonants() {
    Bitset Consonants = 0;
    for (unsigned char i = 'b'; i <= 'z'; ++i) {
        if (i != 'o' && i != 'e' && i!= 'i' && i != 'y' && i != 'u') {
            Consonants = Consonants | (1u << (i - 'a'));
        }
    }
    return Consonants;
}

int Task() {
    // write your solution here
    Bitset Consonants_Set = Consonants();
    int answer = 0;
    int flag = 0;
    Bitset Set = 0;
    unsigned char letter_1;
    unsigned char letter_2;
    letter_1 = getchar();
    letter_2 = letter_1;
    while (1) {
        if ('a' <= letter_1 && letter_1 <= 'z' || 'A' <= letter_1 && letter_1 <= 'Z') {
            if (flag == 0) {
                if ('a' <= letter_1 && letter_1 <= 'z') {
                    Set = Set | (1u << (letter_1 - 'a'));
                } else {
                    Set = Set | (1u << (letter_1 - 'A'));
                }
                flag = 1;
            }
        } else if (flag) {
            if ('a' <= letter_2 && letter_2 <= 'z') {
                Set = Set | (1u << (letter_2 - 'a'));
            } else {
                Set = Set | (1u << (letter_2 - 'A'));
            }
            flag = 0;
            if ((Set & Consonants_Set) == 0) {
                answer = 1;
            }
            Set = 0;
        }
        letter_2 = letter_1;
        if (letter_1 == '\n') {
            break;
        }
        letter_1 = getchar();
    }
    if (answer) {
        printf("Есть слова, начинающиеся и заканчивающиеся гласными.\n");
    } else {
        printf("Нет слов, начинающихся и заканчивающихся гласными.\n");
    }
    return 0;
}
