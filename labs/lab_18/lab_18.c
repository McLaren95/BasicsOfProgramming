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
    // Ищем начало слова, пропуская пробелы
    while (isspace(*beginSearch)) {
        beginSearch++;
    }
    word->begin = beginSearch;

    // Если достигнут конец строки, возвращаем 0
    if (*beginSearch == '\0') {
        return 0;
    }

    // Ищем конец слова, ища первый пробел или конец строки
    while (*beginSearch != '\0' && !isspace(*beginSearch)) {
        beginSearch++;
    }
    word->end = beginSearch;

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

int getWordReverse(char *searchEnd, char *searchStart, WordDescriptor *word) {
    word->end = findNonSpaceReverse(searchEnd, searchStart) + 1;

    if (word->end == searchEnd + 1) {
        word->begin = searchStart + 1;
        return 0;
    }

    word->begin = findSpaceReverse(searchEnd, word->end - 1) + 1;

    return 1;
}

void replaceDigitsBySpaces(char *s) {
    char *readPoint = s;
    char *writePoint = string_buffer;

    while (*readPoint != '\0') {
        if (isdigit(*readPoint)) {
            int digit = *readPoint - '0';

            for (int i = 0; i < digit; i++) {
                *writePoint = ' ';
                writePoint++;
            }
        } else {
            *writePoint = *readPoint;
            writePoint++;
        }
        readPoint++;
    }

    *copy(string_buffer, writePoint, s) = '\0';
}

int compareWords(WordDescriptor left, WordDescriptor right) {
    while (left.begin != left.end && right.begin != right.end && *left.begin == *right.begin) {
        left.begin++;
        right.begin++;
    }

    if (left.begin == left.end && right.begin == right.end) {
        return 0;
    }

    if (left.begin == left.end && right.begin != right.end) {
        return -(*right.begin);
    }

    if (left.begin != left.end && right.begin == right.end) {
        return *left.begin;
    }

    return *left.begin - *right.begin;
}

void replace(char *s, char *w1, char *w2) {
    size_t w1Length = strlen_(w1);
    size_t w2Length = strlen_(w2);
    WordDescriptor w1Word = {w1, w1 + w1Length};
    WordDescriptor w2Word = {w2, w2 + w2Length};
    char *readPoint;
    char *writePoint;

    if (w1Length > w2Length) {
        readPoint = s;
    } else {
        *copy(s, s + strlen_(s), string_buffer) = '\0';
        readPoint = string_buffer;
    }

    writePoint = s;
    WordDescriptor cur_word;

    while (getWord(readPoint, &cur_word)) {
        writePoint = copy(readPoint, cur_word.begin, writePoint);

        if (compareWords(cur_word, w1Word) == 0) {
            writePoint = copy(w2Word.begin, w2Word.end, writePoint);
        } else {
            writePoint = copy(cur_word.begin, cur_word.end, writePoint);
        }

        readPoint = cur_word.end;
    }

    *writePoint = '\0';
}

bool areWordsSorted(char *string) {
    WordDescriptor previousWord;

    if (getWord(string, &previousWord)) {
        WordDescriptor currentWord;

        while (getWord(previousWord.end, &currentWord)) {
            if (compareWords(previousWord, currentWord) > 0) {
                return false;
            }

            previousWord = currentWord;
        }
    }

    return true;
}

bool areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    // Сравниваем длины слов
    size_t length1 = w1.end - w1.begin;
    size_t length2 = w2.end - w2.begin;

    if (length1 != length2) {
        return false;
    }

    // Сравниваем символы слов
    for (size_t i = 0; i < length1; ++i) {
        if (w1.begin[i] != w2.begin[i]) {
            return false;
        }
    }

    return true;
}

void getBagOfWords(char *searchStart, BagOfWords *bag) {
    size_t wordIndex = 0;

    while (getWord(searchStart, bag->words + wordIndex)) {
        searchStart = bag->words[wordIndex].end;
        wordIndex++;
    }

    bag->size = wordIndex;
}

void printWord(WordDescriptor word) {
    if (*word.begin == '\0') {
        return;
    }

    while (word.begin != word.end) {
        putc(*word.begin, stdout);
        word.begin++;
    }
}

void printWordsInReverseOrder(char *string) {
    getBagOfWords(string, &_bag);

    for (size_t i = _bag.size - 1; i != -1; i--) {
        printWord(_bag.words[i]);
        putchar('\n');
    }
}

bool isPalindrome(WordDescriptor word) {
    word.end--;

    while (word.begin < word.end) {
        if (*word.begin != *word.end) {
            return false;
        }

        word.begin++;
        word.end--;
    }

    return true;
}

int countPalindromes(char *string) {
    int count = 0;
    char *searchPoint = string;
    WordDescriptor word;

    while (getWord(searchPoint, &word)) {
        if (isPalindrome(word)) {
            count++;
        }

        searchPoint = word.end;
    }

    return count;
}











