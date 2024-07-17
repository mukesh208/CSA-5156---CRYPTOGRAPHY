#include <stdio.h>
#include <ctype.h>

char encrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)(((a * (ch - base) + b) % 26) + base);
    }
    return ch; 
}

char decrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        int a_inverse = 0;
        for (int i = 1; i < 26; ++i) {
            if ((a * i) % 26 == 1) {
                a_inverse = i;
                break;
            }
        }
        return (char)(((a_inverse * ((ch - base) - b + 26)) % 26) + base);
    }
    return ch; 
}

int main() {
    int a, b;
    char plaintext[1000];

    printf("Enter the value of 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter the value of 'b': ");
    scanf("%d", &b);

    printf("Enter the plaintext message: ");
    scanf(" %[^\n]", plaintext);

    printf("Encrypted message: ");
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        printf("%c", encrypt(plaintext[i], a, b));
    }
    printf("\n");

    printf("Decrypted message (optional): ");
    for (int i = 0; plaintext[i] != '\0'; ++i) {
        printf("%c", decrypt(plaintext[i], a, b));
    }
    printf("\n");

    return 0;
}
