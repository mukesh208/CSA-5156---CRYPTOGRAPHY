#include <stdio.h>
#include <string.h>

int modInverse(int a, int m) {
    for (int x = 1; x < m; ++x) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No inverse exists
}

void calculateInverseMatrix(int keyMatrix[][2], int inverse[][2]) {
    int det = (keyMatrix[0][0] * keyMatrix[1][1] - keyMatrix[0][1] * keyMatrix[1][0] + 26) % 26;
    int detInverse = modInverse(det, 26);

    inverse[0][0] = (keyMatrix[1][1] * detInverse) % 26;
    inverse[0][1] = (-keyMatrix[0][1] * detInverse) % 26;
    inverse[1][0] = (-keyMatrix[1][0] * detInverse) % 26;
    inverse[1][1] = (keyMatrix[0][0] * detInverse) % 26;
}

void decryptHillCipher(char ciphertext[], int inverse[][2]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i += 2) {
        int c1 = ciphertext[i] - 'A';
        int c2 = ciphertext[i + 1] - 'A';

        int p1 = (inverse[0][0] * c1 + inverse[0][1] * c2) % 26;
        int p2 = (inverse[1][0] * c1 + inverse[1][1] * c2) % 26;

        printf("%c%c", p1 + 'A', p2 + 'A');
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "POH";
    int keyMatrix[2][2] = {{6, 24}, {13, 16}};
    int inverseMatrix[2][2];
    calculateInverseMatrix(keyMatrix, inverseMatrix);

    printf("Plaintext: ");
    decryptHillCipher(ciphertext, inverseMatrix);

    return 0;
}
