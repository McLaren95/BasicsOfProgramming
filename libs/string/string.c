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
    while (rend != rbegin && isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rend != rbegin && !isspace(*rbegin)) {
        rbegin--;
    }
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    char left_char, right_char;
    while ((left_char = *(lhs++)) == (right_char = *(rhs++)) && left_char != '\0' && right_char != '\0');
    return (left_char > right_char) - (left_char < right_char);
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t length = endSource - beginSource;
    memcpy(beginDestination, beginSource, sizeof(char) * length);
    beginDestination[length] = '\0';
    return beginDestination + length;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, bool (*f)(char)) {
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
            *beginDestination-- = *rbeginSource;
        }
        rbeginSource--;
    }
    return beginDestination;
}

char *moveStringToHeap(char *string) {
    size_t size = sizeof(char) * (strlen_(string) + 1);
    char *heapString = malloc(size);

    memcpy(heapString, string, size);

    return heapString;
}

void assertString(char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stdout, "%s on line %d - OK\n", funcName, line);
    }
}

void assertBoolean(bool expected, bool got, char const *fileName, char const *funcName, int line) {
    if (got != expected) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", (expected ? "true" : "false"));
        fprintf(stderr, "Got: \"%s\"\n\n", (got ? "true" : "false"));
    } else {
        fprintf(stdout, "%s on line %d - OK\n", funcName, line);
    }
}

void assertInt(int expected, int got, char const *fileName, char const *funcName, int line) {
    if (got != expected) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%d\"\n", expected);
        fprintf(stderr, "Got: \"%d\"\n\n", got);
    } else {
        fprintf(stdout, "%s on line %d - OK\n", funcName, line);
    }
}






