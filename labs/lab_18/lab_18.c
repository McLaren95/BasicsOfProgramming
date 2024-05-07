#include "lab_18.h"

void removeExtraSpaces(char *s) {
    char *outputPointer = s;
    int wasSpaceBefore = 0; // флаг, указывающий, был ли предыдущий символ пробелом

    while (*s != '\0') {
        if (!isspace(*s)) {
            *outputPointer = *s;
            outputPointer++;
            wasSpaceBefore = 0; // сбрасываем флаг, если текущий символ не пробел
        } else {
            if (!wasSpaceBefore) { // если предыдущий символ не был пробелом записываем текущий пробел
                *outputPointer = *s;
                outputPointer++;
                wasSpaceBefore = 1; // устанавливаем флаг, что предыдущий символ был пробелом
            }
        }
        s++;
    }
    // Проверяем, закончилась ли строка на пробел и удаляем его, если это так
    if (wasSpaceBefore) {
        *(outputPointer - 1) = '\0';
    } else {
        *outputPointer = '\0';
    }
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0') {
        return 0;
    }

    word->end = findSpace(word->begin);

    return 1;
}

bool isDigit(char character) {
    return isdigit(character);
}

bool isAlpha(char character) {
    return isalpha(character);
}

void lettersToStartDigitsToEnd(WordDescriptor word) {
    char *stringBufferEnd = copy(word.begin, word.end, string_buffer);
    char *digitsEnd = copyIf(string_buffer, stringBufferEnd, word.begin, isAlpha);

    copyIf(string_buffer, stringBufferEnd, digitsEnd, isDigit);
}

void forEachWord(char *string, void (*function)(WordDescriptor)) {
    char *searchPoint = string;
    WordDescriptor word;

    while (getWord(searchPoint, &word)) {
        function(word);

        searchPoint = word.end;
    }
}
