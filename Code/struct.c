#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct ArrayStruct {
    char data[26];
};

struct PointerStruct {
    char *data;
};

int main() {
printf("PART 1:\n");
struct ArrayStruct A1;
strcpy(A1.data, "Original");

struct ArrayStruct A2 = A1;

strcpy(A2.data, "Modified");
printf("A1 contains: %s\n", A1.data);
printf("A2 contains: %s\n", A2.data);

//-----------------------

printf("\nPART 2:\n");
struct PointerStruct P1;
P1.data = malloc(20 * sizeof(char));
strcpy(P1.data, "Original");

struct PointerStruct P2 = P1;

strcpy(P2.data, "Modified");

printf("P1 contains: %s\n", P1.data);
printf("P2 contains: %s\n", P2.data);

//p1 and p2 point to same chunk of memory so they both (their .data) return "Modified"
}