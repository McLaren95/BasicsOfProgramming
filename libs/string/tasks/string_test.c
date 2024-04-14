#include "../../string/tasks/string_test.h"

void test_1() {
    char *s1 = "Hi";
    char s2[10] = "\tHello\t";
    printf("%u\n", strlen_(s1)); // 2
    printf("%u\n", strlen_(s2)); // 7
}

int test_find(char *s, int ch) {
    char *result = find(s, s + strlen_(s), ch);
    return (result != s + strlen_(s)) ? 1 : 0;
}

void test_2() {
    char s[] = "Hello, World!";
    printf("%d\n", test_find(s, 'e')); // 1
    printf("%d\n", test_find(s, 'z')); // 0
    printf("%d\n", test_find(s, 'a')); // 0
}

int test_findNonSpace(char *s) {
    char *result = findNonSpace(s);
    return (*result != '\0') ? 1 : 0;
}

void test_3() {
    char s[] = "   Hello, World!";
    printf("%d\n", test_findNonSpace(s)); // 1
    printf("%d\n", test_findNonSpace("    ")); // 0
    printf("%d\n", test_findNonSpace("")); // 0
}

int test_findSpace(char *s) {
    char *result = findSpace(s);
    return (*result == ' ') ? 1 : 0;
}

void test_4() {
    char s[] = "Hello,World!";
    printf("%d\n", test_findSpace(s)); // 0
    printf("%d\n", test_findSpace("  Hello, World!")); // 1
    printf("%d\n", test_findSpace("")); // 0
}

int test_findNonSpaceReverse(char *s) {
    char *result = findNonSpaceReverse(s + strlen_(s) - 1, s - 1);
    return (*result != '\0') ? 1 : 0;
}

void test_5() {
    char s[] = "Hello, World!";
    printf("%d\n", test_findNonSpaceReverse(s)); // 1
    printf("%d\n", test_findNonSpaceReverse("  Hello, World!")); // 1
    printf("%d\n", test_findNonSpaceReverse("")); // 0
}

void test_6() {
    char s1[] = "Hello,World!";
    char *result = findSpaceReverse(s1 + strlen_(s1) - 1, s1 - 1);
    if (result != s1 - 1) {
        printf("Test 1 failed\n");
    } else {
        printf("Test 1 passed\n");
    }
}

void test_7() {
    char s1[] = "A";
    char s2[] = "B";
    int result1 = strcmp(s1, s2);
    char s3[] = "A";
    char s4[] = "A";
    int result2 = strcmp(s3, s4);
    char s5[] = "B";
    char s6[] = "A";
    int result3 = strcmp(s5, s6);
    printf("%d\n", result1); //-1
    printf("%d\n", result2); // 0
    printf("%d\n", result3); // 1
}

void test_8() {
    const char *source = "Hello, World!";
    const char *sourceBegin = source;
    const char *sourceEnd = source + strlen_(source);
    char destination[20];
    char *destinationBegin = destination;
    char *result = copy(sourceBegin, sourceEnd, destinationBegin);
    // Проверяем результат копирования
    if (strcmp(destination, source) == 0 && result == destinationBegin + strlen_(source)) {
        printf("Test passed!\n");
    } else {
        printf("Test failed!\n");
    }
}

int isLowerCase(int ch) {
    return (ch >= 'a' && ch <= 'z');
}

void test_9() {
    char source[] = "ABCa";
    char destination[20] = {0};
    char *result = copyIf(source, source + strlen_(source), destination, isLowerCase);
    *result = '\0';
    printf("Result: %s\n", destination); //a
}

int isLetter(int ch) {
    return isalpha(ch);
}

void test_10() {
    char source[] = "Hello, World!";
    char destination[20] = {0};
    char *result = copyIfReverse(source + strlen_(source) - 1, source - 1, destination + strlen_(source) - 1, isLetter);
    printf("Result: %s\n", result + 1); //HelloWorld
}
