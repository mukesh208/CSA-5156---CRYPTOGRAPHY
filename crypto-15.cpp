#include <stdio.h>
#include <string.h>

void decryptWithFrequencyAttack(char ciphertext[], int length) {
    char plaintext[10][100]; // Store the top 10 possible plaintexts
    int freq[26] = {0}; // Frequency of each letter in the ciphertext

    // Calculate letter frequencies
    for (int i = 0; i < length; ++i) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            freq[ciphertext[i] - 'A']++;
        }
    }

    // Sort frequencies in descending order
    int sortedFreq[26];
    for (int i = 0; i < 26; ++i) {
        sortedFreq[i] = freq[i];
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 26; ++j) {
            if (sortedFreq[j] > sortedFreq[i]) {
                int temp = sortedFreq[i];
                sortedFreq[i] = sortedFreq[j];
                sortedFreq[j] = temp;
            }
        }
    }

    // Decrypt using frequency analysis
    for (int i = 0; i < 5; ++i) {
        int diff = 'E' - 'A' - (sortedFreq[i] - 'A');
        for (int j = 0; j < length; ++j) {
            if (ciphertext[j] >= 'A' && ciphertext[j] <= 'Z') {
                plaintext[i][j] = 'A' + ((ciphertext[j] - 'A' + diff + 26) % 26);
            } else {
                plaintext[i][j] = ciphertext[j]; // Non-alphabetic characters remain unchanged
            }
        }
        plaintext[i][length] = '\0';
    }

    // Print the top 10 possible plaintexts
    for (int i = 0; i < 5; ++i) {
        printf("Plaintext %d: %s\n", i + 1, plaintext[i]);
    }
}

int main() {
    char ciphertext[] = "VQREQFGT";
    int length = strlen(ciphertext);

    decryptWithFrequencyAttack(ciphertext, length);

    return 0;
}
