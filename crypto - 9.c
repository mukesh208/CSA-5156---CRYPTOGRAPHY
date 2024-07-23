#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void findPosition(char ch, int *row, int *col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void decryptPlayfair(char ciphertext[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        char ch1 = toupper(ciphertext[i]);
        char ch2 = toupper(ciphertext[i + 1]);

        int row1, col1, row2, col2;
        findPosition(ch1, &row1, &col1);
        findPosition(ch2, &row2, &col2);

        if (row1 == row2) {
            printf("%c%c", matrix[row1][(col1 + 4) % 5], matrix[row2][(col2 + 4) % 5]);
        } else if (col1 == col2) {
            printf("%c%c", matrix[(row1 + 4) % 5][col1], matrix[(row2 + 4) % 5][col2]);
        } else {
            printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char keyword[] = "CIPHER";
    char unusedLetters[] = "ABDFGJKLMOQSTUVWXYZ";

    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < strlen(keyword)) {
                matrix[i][j] = keyword[k++];
            } else {
                matrix[i][j] = unusedLetters[k - strlen(keyword)];
            }
        }
    }

    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";

    printf("Decrypted message:\n");
    decryptPlayfair(ciphertext);

    return 0;
}
