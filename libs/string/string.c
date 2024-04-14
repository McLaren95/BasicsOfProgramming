#include "string.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0') {
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rend != rbegin && isspace(*rend)) {
        rend--;
    }
    return rend;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rend != rbegin && !isspace(*rend)) {
        rend--;
    }
    return rend;
}

int strcmp(const char *lhs, const char *rhs) {
    char left_char, right_char;
    while ((left_char = *(lhs++)) == (right_char = *(rhs++)) && left_char != '\0' && right_char != '\0');
    return (left_char > right_char) - (left_char < right_char);
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t length = endSource - beginSource;
    memcpy(beginDestination, beginSource, sizeof(char) * length);
    return beginDestination + length;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination++, beginSource, sizeof(char));
        }
        beginSource++;
    }
    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    while (rbeginSource != rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination++, rbeginSource, sizeof(char));
        }
        rbeginSource--;
    }
    return beginDestination;
}