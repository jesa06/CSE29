#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    size_t count = 0;

    // Read in command line argument as length of array
    count = atoi(argv[1]);

    // Allocate array for that size
    int64_t *numbers = malloc(count * sizeof(int64_t));
	
    // the heap can fail to find memory for you to malloc
    if (numbers == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }
    // assign every integer to have a number 0, 10, 20, 30,...
    for (size_t i = 0; i < count; i++) {
        numbers[i] = (int64_t)(i + 1) * 10; // Assign 10 * Index to the array value
    }

    for (size_t i = 0; i < count; i++) {
        printf("numbers[%lu] = %llu \n", i, numbers[i]);
    }

    free(numbers);
    return EXIT_SUCCESS;
}
