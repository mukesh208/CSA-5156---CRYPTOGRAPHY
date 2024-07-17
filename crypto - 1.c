#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - base + key) % 26 + base;
        }
    }
}

int main() {
    char message[100];
    int key;

    printf("Enter a message: ");
    scanf("%s", message);

    printf("Enter the key (1 to 25): ");
    scanf("%d", &key);

    printf("Original Message: %s\n", message);
    encrypt(message, key);
    printf("Encrypted Message: %s\n", message);

    encrypt(message, 26 - key);
    printf("Decrypted Message: %s\n", message);

    return 0;
}

