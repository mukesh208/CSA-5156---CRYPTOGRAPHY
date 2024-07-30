#include <stdio.h>
char alpha[27][3] = {
    {'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'}, {'e', 'n'},
    {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'},
    {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'},
    {'p', 't'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'},
    {'u', 'z'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'},
    {'z', 'h'}
};
char monocipher_encr(char a) {
    for (int i = 0; i < 27; i++) {
        if (a == alpha[i][0]) {
            return alpha[i][1];
        }
    }
    return a;
}

int main() {
    char str[20], str2[20];
    printf("\nEnter a string: ");
    gets(str);
	int i;
    for (int i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0';

    printf("\nOriginal string: %s", str);
    printf("\nEncrypted string: %s\n", str2);

    return 0;
}
