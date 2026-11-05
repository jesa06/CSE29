#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// Binary to Signed 8-bit Integer
// Given a char[8] representing a binary number, returns the signed 8-bit integer it represents
// For example:
//   "10000000" produces -128 (most negative 8-bit number)
//   "00000001" produces 1
//   "00000000" produces 0
//   "11111111" produces -1
//   "01111111" produces 127 (most positive 8-bit number)
int8_t bin8_to_dec(char binary[]){
    int sum = 0;

    if (binary[0] == '1') { // signed int
        sum = -128;
    } else {
        sum = 0; // unsigned int
    }

    for (int i = 1; i < 8; i++) {
        if (binary[i] == '1') {
            sum = sum + (1 << (7-i));
        }
    }

    return (int8_t)sum;
}

// --------------------------------------------------

// Given a char[] of ASCII '0' and '1' (length ≤ 32), print the unsigned 32-bit integer it represents.
// If the string is shorter than 32, assume leading 0's.
void bin_to_dec(char str[]) {
    uint32_t sum = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        int bit = str[i] - '0';
        sum = (sum << 1) | bit;
    }
    printf("%u\n", sum);
}

// --------------------------------------------------

// Binary to Signed 32-bit Integer
// Write a function that takes a null-terminated char[] consisting of ASCII '0' and '1' characters (length ≤ 32)
// and prints out the signed 32-bit integer it represents (using two's complement for negatives).
// If the string is less than 32 characters, sign-extend the most significant bit (the leftmost bit)
// up to 32 characters (e.g., "110" is treated as "111...110" and represents -2).
// Given a char[] of ASCII '0' and '1' (length ≤ 32), print the signed 32-bit integer it represents.
void bin_to_dec_signed(char str[]) {
    int32_t decimal;

    if (str[0] == '0') {
        decimal = 0;
    } else {
        decimal = -1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        decimal = (decimal << 1) | str[i] - '0';
    }

    printf("%d\n", decimal);
}

// --------------------------------------------------

// Extract Least Significant 16 Bits
// Given a uint32_t, returns the least significant (rightmost) 16 bits as a uint16_t
// For example:
//   0xFFFFFFFF -> 0xFFFF (65535)
//   0x00000000 -> 0x0000 (0)
//   0x00010001 -> 0x0001 (1)
//   0x80008000 -> 0x8000 (32768)
//   0xDEADBEEF -> 0xBEEF (48879)
uint16_t second_half(uint32_t number) {
    uint16_t result;
    result = (number & 0x0000FFFF); // F is 1111
    return result;
    // OR JUST ONE LINE return number & 0x0000FFFF;
}

// --------------------------------------------------

// Extract Most Significant 16 Bits
// Given a uint32_t, returns the most significant (leftmost) 16 bits as a uint16_t
// For example:
//   0xFFFFFFFF -> 0xFFFF (65535)
//   0x00000000 -> 0x0000 (0)
//   0x00010000 -> 0x0001 (1)
//   0x80000000 -> 0x8000 (32768)
//   0xDEADBEEF -> 0xDEAD (57005)
uint16_t first_half(uint32_t number) {
    return (number & 0xFFFF0000) >> 16;
}

// --------------------------------------------------

// Starts with 10
// Given a char, returns 1 if it starts with the bits `10` and 0 if it does not
// For example:
//   0b10110101 -> 1 (starts with 10)
//   0b11000000 -> 0 (starts with 11)
//   0b01110000 -> 0 (starts with 01)
//   0b10000000 -> 1 (starts with 10)
//   0b00001111 -> 0 (starts with 00)
int starts_with_10(char c) {
    if ((c & 0b11000000) == 0b10000000) {
        return 1;
    }
    return 0;
}

// --------------------------------------------------

// Bitwise is Even
// Given a int8_t, return 1 if the number is even or 0 if the number is odd only using bitwise operators
// For example:
// Input -> Output
// 0 -> 1
// 1 -> 0
// -2 -> 1
// 29 -> 0
int bitwise_is_even(int8_t n) {
    // even if LSB is 0 
    if ((n & 0b00000001) == 0) {
        return 1;
    }
    return 0;
}

// --------------------------------------------------

// Count 1 Bits
// Given a 32-bit integer, return the number of 1 bits (aka the popcount/hamming weight) only using bitwise operators
// For example:
// Input -> Output
// 128 -> 1
//-1 -> 32
// 0 -> 0
// 2147483647 -> 31
int count_1_bits(int32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if (n & 1) {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

// --------------------------------------------------

// Extract Lowest N Bits
// Given a 32-bit unsigned integer x and an unsigned 8-bit integer n,
// return an unsigned 32-bit integer containing just the least n significant bits of x.
// If n is greater than or equal to 32, return x unchanged.
// If n is 0, return 0.
// For example:
//   x = 0xABCDEF12, n = 4 produces 0x00000002 (keeps only last 4 bits: 0010)
//   x = 0x89ABCDEF, n = 12 produces 0x00000DEF (keeps last 12 bits)
//   x = 0xFFFFFFFF, n = 0 produces 0x00000000 (keeps no bits)
//   x = 0x12345678, n = 40 produces 0x12345678 (n >= 32, returns original)
uint32_t lowest_n(uint32_t x, uint8_t n) {
    if (n >= 32) {
        return x;
    } else if (n == 0) {
        return 0;
    }

    uint32_t mask = 0;

    for (int i = 0; i < n; i++) { // build mask bit by bit
        mask = (mask << 1) | 0b00000001; // mask is basically n 1's
    }      
    return x & mask;
}

// --------------------------------------------------
 
// Print Characters Forward
// Given a char[] of characters, print the char representation and int representation
// For example:
// Input: "abc"
// Output:
// a 97
// b 98
// c 99
void print_abc_char_and_int(char str[]) {
    int length = strlen(str); // number of characters before the null terminator '\0'
    for (int i = 0; i < length; i++) {
        printf("%c %d\n", str[i], str[i]);
    }
}

// --------------------------------------------------
 
// Print Characters Backward
// Given a char[] of characters, print the char representation and int representation backwards
// For example:
// Input: "abc"
// Output:
// c 99
// b 98
// a 97
void print_abc_char_and_int_backwards(char str[]) {
    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        printf("%c %d\n", str[i], str[i]);
    }
}

// --------------------------------------------------

// Check if String is ASCII
// Returns `1` if the given string contains only ASCII characters (or
// is empty), and `0` if there are any non-ASCII characters in the string
uint8_t is_ascii(char str[]) {
    uint8_t result = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 0) || (str[i] > 127)) {
            return 0;
        } 
    }
    return result;
}

// --------------------------------------------------

// Capitalize ASCII Letters
// Returns the number of characters capitalized and capitalizes the lowercase 
// a-z ASCII characters of str in-place.
int32_t capitalize_ascii(char str[]) {
    int32_t count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a') && (str[i] <= 'z')) {
            str[i] = str[i] & 0b11011111; // turn bit 32 off (AKA subtract 32)
            count++; // increment count on lowercase letter
        }
    }

    return count;
}

// --------------------------------------------------

// Convert to Lowercase
// Returns the number of characters lowercased and lowercases the capitalized 
// A-Z ASCII characters of str in-place.
int32_t to_lowercase(char str[]) {
    int32_t count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'A') && (str[i] <= 'Z')) {
            str[i] = str[i] | 0b00100000;
            count++;
        }
       
    }

    return count;
}

// ---------------------------------------------------

// Fint UTF-8 Codepoint at Byte Index
// Given a char[] representing a UTF-8 encoded string, and a byte index,
// return the decimal codepoint value of the Unicode character that starts at that byte index,
// or -1 if the byte at that index cannot be the start of a valid UTF-8 character.
//
// For example:
//   "Hello", 0 -> 72 (H has codepoint value 72)
//   "Hello", 4 -> 111 (o has codepoint value 111)
//   "Café", 3 -> 233 (é has codepoint value 233)
//   "🌟star", 0 -> 127775 (🌟 has codepoint value 127775)
//   "🌟star", 1 -> -1 (byte is 10xxxxxx continuation byte)
//   "🌟star", 4 -> 115 (s has codepoint value 115)
int32_t codepoint_at(char str[], int32_t byte_index) {
    // edge cases
    if ((strlen(str) == 0) || (byte_index < 0)) {
        return -1;
    }

    if (byte_index >= strlen(str)) {
        return -1;
    }

    uint8_t firstByte = (uint8_t)str[byte_index];
    uint32_t  decCodepoint;
    int bytes;

    // find number of bytes AND first data bits
    if ((firstByte & 0b10000000) == 0) { // 1 byte == ASCII
        return firstByte;
    } else if ((firstByte & 0b11100000) == 0b11000000) {
        bytes = 2;
        decCodepoint = firstByte & 0b00011111;
    } else if ((firstByte & 0b11110000) == 0b11100000) {
        bytes = 3;
        decCodepoint = firstByte & 0b00001111;
    } else if ((firstByte & 0b11111000) == 0b11110000) {
        bytes = 4;
        decCodepoint = firstByte & 0b00000111;
    } else {
        return -1;
    }

    // handles all continuation bytes, start on 1 bc already handled the start byte
    for (int i = 1; i < bytes; i++) {
        if (str[byte_index + i] == '\0') {
            return -1;
        }

        uint8_t nextByte = (uint8_t)str[byte_index + i];
        // check for valid continuation byte
        if ((nextByte & 0b11000000) != 0b10000000) {
            return -1;
        }

        decCodepoint = (decCodepoint << 6) | (nextByte & 0b00111111);

    }

    // Reject overlong encodings
    if ((bytes == 2 && decCodepoint < 0x80) ||
        (bytes == 3 && decCodepoint < 0x800) ||
        (bytes == 4 && decCodepoint < 0x10000)) {
        return -1;
    }

    // Reject UTF-16 surrogate values
    if (decCodepoint >= 0xD800 && decCodepoint <= 0xDFFF) {
        return -1;
    }

    // Reject codepoints above the Unicode maximum
    if (decCodepoint > 0x10FFFF) {
        return -1;
    }

    return decCodepoint;
}

// project 1 resubmission extra function 
void next_utf8_char(char str[], int32_t cpi, char result[]) {
    int32_t oldCP = codepoint_at(str, cpi);
    if (oldCP == -1) {
        result[0] = '\0';
        return;
    }

    // Calculate the next code point
    int32_t newCP = oldCP + 1;

    if (newCP <= 0x7F) {
        // Encode using 1 byte
        result[0] = newCP;
        result[1] = '\0';
    } else if (newCP <= 0x7FF) {
    // Encode using 2 bytes
        result[0] = 0b11000000 | (newCP >> 6); //move cont bits over
        result[1] = 0b10000000 | (newCP & 0b00111111);
        result[2] = '\0';
    } else if (newCP <= 0xFFFF) {
    // Encode using 3 bytes
        result[0] = 0b11100000 | (newCP >> 12);
        result[1] = 0b10000000 | ((newCP >> 6) & 0b00111111);
        result[2] = 0b10000000 | (newCP & 0b00111111);
        result[3] = '\0';
    } else {
    // Encode using 4 bytes
        result[0] = 0b11110000 | (newCP >> 18);
        result[1] = 0b10000000 | ((newCP >> 12) & 0b00111111);
        result[2] = 0b10000000 | ((newCP >> 6) & 0b00111111);
        result[3] = 0b10000000 | (newCP & 0b00111111);
        result[4] = '\0';
    }
    
}

int main() {
    // binary to signed 8-bit int
    char inputStr[1000];
    fgets(inputStr, sizeof(inputStr), stdin);
    int8_t result = bin8_to_dec(inputStr);
    printf("%d\n", result);

    // binary to unsigned 32-bit int
    char binStr[1000];
    fgets(binStr, sizeof(binStr), stdin);
    bin_to_dec(binStr);

    int32_t idx = 3;
    next_utf8_char(inputStr, idx, result);
    printf("Next character of code point at index 3: %s\n", result);
}