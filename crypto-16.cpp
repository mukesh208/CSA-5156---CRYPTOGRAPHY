#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Frequency of letters in English language
const float english_freq[ALPHABET_SIZE] = {
    8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015, 6.094, 6.966, 0.153,
    0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987, 6.327, 9.056,
    2.758, 0.978, 2.360, 0.150, 1.974, 0.074
};

void count_frequencies(const char *text, int freq[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        freq[i] = 0;
    for (int i = 0; text[i]; i++)
        if (isalpha(text[i]))
            freq[toupper(text[i]) - 'A']++;
}

void decrypt(const char *ciphertext, char *plaintext, const int key[ALPHABET_SIZE]) {
    for (int i = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            int index = toupper(ciphertext[i]) - 'A';
            char decrypted_char = key[index] + (islower(ciphertext[i]) ? 'a' : 'A');
            plaintext[i] = decrypted_char;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void find_key(const int cipher_freq[ALPHABET_SIZE], int key[ALPHABET_SIZE]) {
    int used[ALPHABET_SIZE] = {0};
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        float min_diff = 100.0;
        int best_match = -1;
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (!used[j]) {
                float diff = abs(cipher_freq[i] - english_freq[j]);
                if (diff < min_diff) {
                    min_diff = diff;
                    best_match = j;
                }
            }
        }
        key[i] = best_match;
        used[best_match] = 1;
    }
}

int main() {
    char ciphertext[] = "YOUR MONOALPHABETIC CIPHER TEXT HERE";
    int cipher_freq[ALPHABET_SIZE];
    int key[ALPHABET_SIZE];
    char plaintext[strlen(ciphertext) + 1];

    count_frequencies(ciphertext, cipher_freq);
    find_key(cipher_freq, key);
    decrypt(ciphertext, plaintext, key);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}
