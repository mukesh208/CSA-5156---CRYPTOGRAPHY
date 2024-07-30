#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int key[2][2] = {
    {9, 4},
    {5, 7}
};

int letterToNumber(char ch) {
    return toupper(ch) - 'A';
}

char numberToLetter(int num) {
    return 'A' + num;
}

void encryptHill(char plaintext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        int num1 = letterToNumber(plaintext[i]);
        int num2 = letterToNumber(plaintext[i + 1]);

        int encryptedNum1 = (key[0][0] * num1 + key[0][1] * num2) % 26;
        int encryptedNum2 = (key[1][0] * num1 + key[1][1] * num2) % 26;

        printf("%c%c ", numberToLetter(encryptedNum1), numberToLetter(encryptedNum2));
    }
    printf("\n");
}

int main() {
    char plaintext[] = "meetmeattheusualplaceattenratherthaneightoclock"; // Your plaintext here

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    encryptHill(plaintext);

    return 0;
}
