#include "../../libs/string/string.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

static BagOfWords _bag;
static BagOfWords _bag2;

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

//заменяет все цифры в строке на пробелы, в соответствии с их числовым значением.
void replaceDigitsBySpaces(char *s);

//сравнивает два слова, представленных структурами WordDescriptor,
// и возвращает результат сравнения на основе лексикографического порядка.
int compareWords(WordDescriptor left, WordDescriptor right);

//заменяет в строке source все вхождения подстроки w1 на подстроку w2.
void replace(char *source, char *w1, char *w2);

//проверяет, упорядочены ли слова лексикографически в данном предложении, сравнивая каждое слово с предыдущим
// и возвращая false, если какое-либо слово идет после другого в алфавитном порядке, иначе возвращает true.
bool areWordsSorted(char *string);

//сравнивает два слова, проверяя их длины и затем сравнивая каждый символ, чтобы определить, равны ли они,
// и возвращает true, если слова идентичны, и false в противном случае.
bool areWordsEqual(WordDescriptor w1, WordDescriptor w2);

//получает позиции начала и конца каждого слова строки.
void getBagOfWords(char *searchStart, BagOfWords *bag);

//выводит слово, представленное структурой WordDescriptor, на стандартный вывод (stdout).
void printWord(WordDescriptor word);

//печатает слова из строки в обратном порядке.
void printWordsInReverseOrder(char *string);

//проверяет, является ли слово, заданное структурой WordDescriptor, палиндромом.
bool isPalindrome(WordDescriptor word);

//подсчитывает количество палиндромов в строке, разбивая строку на слова
// и проверяя каждое слово на палиндромность.
int countPalindromes(char *string);

//объединяет слова из двух строк в чередующимся порядке,
// используя пробел в качестве разделителя, и записывает результат в третью строку.
void alternateWordsMerge(char *left, char *right, char *destination);