#include <stdio.h>


struct NetworkData {
    int id; // 4 byte
    char buffer[1024]; // 1024 bytes
};

void process_data(char data_array[1024]) {
    printf("Function Size: = %zu\n", sizeof(data_array)); 
}

void process_data2(struct NetworkData x) {
    printf("Function Size: = %zu\n", sizeof(x.buffer)); 
}

int main() {
    struct NetworkData net;
    printf("Function Size: = %zu\n", sizeof(net.buffer)); //1024 bytes
    process_data(net.buffer); // 8 bytes
    process_data2(net); // 1024

}