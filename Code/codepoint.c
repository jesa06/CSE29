#include <stdint.h>
#include <stdio.h>

int main(void)
{
    const char text[] = "Ã©";
    const uint8_t *bytes = (const uint8_t *)text;

    uint32_t codepoint =
        ((uint32_t)(bytes[0] & 0b00011111) << 6) | (bytes[1] & 0b00111111);

    printf("Character: %s\n", text);
    printf("UTF-8:    0b11000011 0b10101001\n");
    printf("Codepoint: U+%04X %d\n", (unsigned int)codepoint, codepoint);

    return 0;
}
