#include "../../libs/string/string.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

//Сократить количество пробелов между словами данного предложения до одного.
void removeExtraSpaces(char *s);

//вернёт значение 0, если слово не было считано, в противном
//случае будет возвращено значение 1 и в переменную word типа WordDescriptor
//будут записаны позиции начала слова, и первого символа после конца слова
int getWord(char *beginSearch, WordDescriptor *word);

//чтобы цифры каждого слова были
//перенесены в конец слова без изменения порядка следования их в слове, а
//буквы – в начало
void lettersToStartDigitsToEnd(WordDescriptor word);

//проходит по каждому слову в строке, используя функцию function для обработки каждого слова.
void forEachWord(char *string, void (*function)(WordDescriptor));

bool isDigit(char character);

bool isAlpha(char character);

int getWordReverse(char *searchEnd, char *searchStart, WordDescriptor *word);

void replaceDigitsBySpaces(char *s);