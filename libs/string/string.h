#ifndef INC_STRING_H
#define INC_STRING_H

#include <stddef.h>


//возвращает количество символов в строке (не считая ноль-символ)
size_t strlen_(const char *begin);

//возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
//адресами begin и end не включая end
char *find(char *begin, char *end, int ch);


#endif