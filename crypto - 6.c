#include <stdio.h>

int modInverse(int a) {
    for (int x = 1; x < 26; x++) {
        if ((a * x) % 26 == 1) {
            return x;
        }
    }
    return -1; 
}

void decryptAffineCipher(char ciphertext[], int a, int b) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int y = ciphertext[i] - 'A';
            int x = modInverse(a) * (y - b + 26) % 26;
            printf("%c", 'A' + x);
        } else {
            printf("%c", ciphertext[i]); 
        }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "YOUR_CIPHERTEXT_HERE"; 
    for (int a = 1; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            decryptAffineCipher(ciphertext, a, b);
        }
    }

    return 0;
}
