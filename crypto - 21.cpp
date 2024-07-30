#include <stdio.h>
#include <stdint.h>
#include <string.h>

void pad_message(uint8_t *message, size_t *length, size_t block_size) {
    size_t pad_len = block_size - (*length % block_size);
    for (size_t i = 0; i < pad_len; i++) {
        message[*length + i] = (i == 0) ? 0x80 : 0x00;
    }
    *length += pad_len;
}

int main() {
    uint8_t plaintext[] = "YOUR PLAINTEXT HERE";
    size_t length = strlen((char *)plaintext);
    size_t block_size = 8; // Example block size for DES

    pad_message(plaintext, &length, block_size);

    printf("Padded message: ");
    for (size_t i = 0; i < length; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    return 0;
}
