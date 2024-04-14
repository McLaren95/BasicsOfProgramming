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