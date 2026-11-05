
#include <stdio.h>
#include <string.h>


char* newArray() { // makes a new array
    char new[10]; // allocate
    printf("new[0] %d\n", new[0]);
    new[0] = 0;
    printf("new array: %p\n", new); // every time function is called, it is stored in same memory --> WILL BE OVERWRITTEN
    return new;
}
/*
void blah() {
    char giant[10000];
    for (int i = 0; i )
    printf("giant: %p\n", giant); 
} */

int main() {
    for (int i = 0; i < 10; i ++) {
        char* arr = newArray();
        printf("ARR[0] %d\n", arr[0]);
        arr[0] = i; /
    }
  
        return 0;
}
