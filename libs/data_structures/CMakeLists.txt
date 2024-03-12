add_library(data_structures
            bitset/bitset.c
        unordered_array_set/unordered_array_set.c
        unordered_array_set/unordered_array_set.h
        ordered_array_set/ordered_array_set.h
        ordered_array_set/ordered_array_set.c
        vector/vector.h
        vector/vector.c
        vector/vectorVoid.h
        vector/vectorVoid.c
        matrix/matrix.h
        matrix/matrix.c
)
target_link_libraries(data_structures algorithms)