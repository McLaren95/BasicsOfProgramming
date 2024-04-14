#ifndef INC_STRING_H
#define INC_STRING_H

#include <stddef.h>
#include <ctype.h>

//возвращает количество символов в строке (не считая ноль-символ)
size_t strlen_(const char *begin);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end. Если символ не найден, возвращается значение end.
char *find(char *begin, char *end, int ch);

// возвращает указатель на первый
//символ, отличный от пробельных, расположенный на ленте памяти,
// начиная с begin и заканчивая ноль-символом. Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin);

#endif