#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateCipherSequence(char keyword[], char sequence[]) {
    int i, j;
    int len = strlen(keyword);

    strcpy(sequence, keyword);

    for (i = len, j = 0; i < 26; i++) {
        char letter = 'A' + j;
        if (strchr(keyword, letter) == NULL) {
            sequence[i] = letter;
            j++;
        }
    }
    sequence[i] = '\0'; 
}

void encryptMonoalphabetic(char plaintext[], char sequence[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            char uppercaseChar = toupper(plaintext[i]);
            int index = uppercaseChar - 'A';
            printf("%c", sequence[index]);
        } else {
            printf("%c", plaintext[i]); 
        }
    }
    printf("\n");
}

int main() {
    char keyword[] = "CIPHER";
    char sequence[27]; 
    generateCipherSequence(keyword, sequence);

    char plaintext[] = "HELLO"; 
    encryptMonoalphabetic(plaintext, sequence);

    return 0;
}
