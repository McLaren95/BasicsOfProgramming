cmake_minimum_required(VERSION 3.26)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/algorithm.c
        libs/algorithms/algorithm.h
        libs/data_structures/bitset/bitset.c
        libs/data_structures/bitset/bitset.h
        labs/lab_16/lab_16.c
        labs/lab_16/lab_16.h
        labs/tests/lab_16_tests.c
        labs/tests/lab_16_tests.h
        libs/string/string.c
        libs/string/string.h
        libs/string/tasks/string_test.h
        libs/string/tasks/string_test.c
        DiskretMath/diskretmath.h
        DiskretMath/diskretmath.c
        labs/lab_18/lab_18.h
        labs/lab_18/lab_18.c
        labs/tests/lab_18_tests.c
        labs/tests/lab_18_tests.h
        labs/lab_19/lab_19.c
        labs/lab_19/lab_19.h
        labs/lab_20/lab_20.c
        labs/lab_20/lab_20.h
)

add_subdirectory(libs)
target_link_libraries(untitled algorithms)
target_link_libraries(untitled data_structures)


