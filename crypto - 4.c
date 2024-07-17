#include <stdio.h>
#include <ctype.h> 
#include <string.h>
void vigenereEncrypt(char plaintext[], char keyword[]) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keywordLen = strlen(keyword);

    for (i = 0, j = 0; i < plaintextLen; ++i) {
        char currentChar = plaintext[i];
        char keywordChar = keyword[j % keywordLen]; 
        if (isalpha(currentChar)) {
            currentChar = toupper(currentChar);
            keywordChar = toupper(keywordChar);
            int shift = keywordChar - 'A';
            char encryptedChar = ((currentChar - 'A' + shift) % 26) + 'A';

            printf("%c", encryptedChar);
            ++j; 
        } else {
            printf("%c", currentChar);
        }
    }
}

int main() {
    char plaintext[100];
    char keyword[20];

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    printf("Enter the keyword: ");
    scanf("%s", keyword);

    printf("Ciphertext: ");
    vigenereEncrypt(plaintext, keyword);
    printf("\n");

    return 0;
}
