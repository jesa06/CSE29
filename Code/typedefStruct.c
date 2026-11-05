#include <stdio.h>
#include <stdint.h>

#define MAX_ARGS 5

typedef struct SimpleStruct {
    char *ptr;
    uint32_t x;
    int y;
} SimpleStruct;

typedef struct ComplexStruct {
    char some_char;
    char *ptr;
    char *args[MAX_ARGS];
    uint32_t ret;
} ComplexStruct;

int main() {
    printf("sizeof(SimpleStruct) = %lu\n", sizeof(SimpleStruct));
    printf("sizeof(ComplexStruct) = %lu\n", sizeof(ComplexStruct));

}