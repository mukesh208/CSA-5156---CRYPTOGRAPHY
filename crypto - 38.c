#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toLowerCase(char plain[], int ps) {
	for (int i = 0; i < ps; i++) {
		if (plain[i] >= 'A' && plain[i] <= 'Z')
			plain[i] += 32;
	}
}
int removeSpaces(char* plain, int ps) {
	int i, j;
	for (i = j = 0; i < ps; i++) {
		if (plain[i] != ' ')
			plain[j++] = plain[i];
	}
	plain[j] = '\0';
	return j;
}

void generateKeySquare(char key[], char keySquare[5][5]) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			while (strchr(key, 'A' + k) || strchr(key, 'a' + k))
				k++;
			if (k == 9)
				k++;
			keySquare[i][j] = 'A' + k;
			k++;
		}
	}
}

void findPosition(char keySquare[5][5], char ch, int* row, int* col) {
	if (ch == 'J')
		ch = 'I';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (keySquare[i][j] == ch) {
				*row = i;
				*col = j;
				return;
			}
		}
	}
}

void encryptDigraph(char keySquare[5][5], char a, char b) {
	int row1, col1, row2, col2;
	findPosition(keySquare, a, &row1, &col1);
	findPosition(keySquare, b, &row2, &col2);

	if (row1 == row2) {
		printf("%c%c", keySquare[row1][(col1 + 1) % 5], keySquare[row2][(col2 + 1) % 5]);
	} else if (col1 == col2) {
		printf("%c%c", keySquare[(row1 + 1) % 5][col1], keySquare[(row2 + 1) % 5][col2]);
	} else {
		printf("%c%c", keySquare[row1][col2], keySquare[row2][col1]);
	}
}

int main() {
	char key[30], plain[100];
	printf("Enter the key: ");
	gets(key);

	char keySquare[5][5];
	generateKeySquare(key, keySquare);

	printf("Enter the plaintext: ");
	gets(plain);

	toLowerCase(plain, strlen(plain));
	int ps = removeSpaces(plain, strlen(plain));

	printf("Encrypted text: ");
	for (int i = 0; i < ps; i += 2) {
		encryptDigraph(keySquare, plain[i], plain[i + 1]);
	}
	printf("\n");

	return 0;
}
