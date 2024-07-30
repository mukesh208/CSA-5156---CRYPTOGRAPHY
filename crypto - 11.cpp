#include <stdio.h>
#include <string.h>
#include <ctype.h>
const char key[5][5] = {
    {'P', 'L', 'A', 'Y', 'F'},
    {'I', 'R', 'C', 'E', 'S'},
    {'T', 'U', 'B', 'D', 'G'},
    {'H', 'K', 'M', 'N', 'O'},
    {'Q', 'V', 'W', 'X', 'Z'}
};

void findPosition(char ch, int *row, int *col) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (key[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPlayfair(char plaintext[]) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; i += 2) {
        char ch1 = toupper(plaintext[i]);
        char ch2 = toupper(plaintext[i + 1]);

        int row1, col1, row2, col2;
        findPosition(ch1, &row1, &col1);
        findPosition(ch2, &row2, &col2);

        if (row1 == row2) {
            printf("%c%c ", key[row1][(col1 + 1) % 5], key[row2][(col2 + 1) % 5]);
        } else if (col1 == col2) {
            printf("%c%c ", key[(row1 + 1) % 5][col1], key[(row2 + 1) % 5][col2]);
        } else {
            printf("%c%c ", key[row1][col2], key[row2][col1]);
        }
    }
    printf("\n");
}

int main() {
    char plaintext[] = "hello world"; 
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    encryptPlayfair(plaintext);

    return 0;
}
