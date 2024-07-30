#include <stdio.h>
#include <stdint.h>
#include <string.h>

void ecb_encrypt(const uint8_t *plaintext, uint8_t *ciphertext, const uint64_t key) {
    // Implement ECB encryption
    // This is a placeholder for the actual ECB encryption logic
    // In a real implementation, you would use a proper encryption function here
    for (size_t i = 0; i < strlen((char *)plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ ((key >> (8 * (i % 8))) & 0xFF); // Simple XOR with key for demonstration
    }
}

void cbc_encrypt(const uint8_t *plaintext, uint8_t *ciphertext, const uint64_t key, const uint64_t iv) {
    // Implement CBC encryption
    // This is a placeholder for the actual CBC encryption logic
    uint64_t previous_block = iv;
    for (size_t i = 0; i < strlen((char *)plaintext); i += 8) {
        uint64_t block = 0;
        for (size_t j = 0; j < 8; j++) {
            block |= ((uint64_t)plaintext[i + j] << (8 * j));
        }
        block ^= previous_block;
        uint64_t encrypted_block = block ^ key; // Simple XOR with key for demonstration
        previous_block = encrypted_block;
        for (size_t j = 0; j < 8; j++) {
            ciphertext[i + j] = (encrypted_block >> (8 * j)) & 0xFF;
        }
    }
}

int main() {
    uint8_t plaintext[] = "YOUR PLAINTEXT HERE";
    uint8_t ecb_ciphertext[strlen((char *)plaintext)];
    uint8_t cbc_ciphertext[strlen((char *)plaintext)];
    uint64_t key = 0x133457799BBCDFF1; // Replace with your actual key
    uint64_t iv = 0x1234567890ABCDEF; // Replace with your actual initialization vector

    ecb_encrypt(plaintext, ecb_ciphertext, key);
    cbc_encrypt(plaintext, cbc_ciphertext, key, iv);

    printf("ECB Ciphertext: ");
    for (size_t i = 0; i < strlen((char *)plaintext); i++) {
        printf("%02x", ecb_ciphertext[i]);
    }
    printf("\n");

    printf("CBC Ciphertext: ");
    for (size_t i = 0; i < strlen((char *)plaintext); i++) {
        printf("%02x", cbc_ciphertext[i]);
    }
    printf("\n");

    return 0;
}
