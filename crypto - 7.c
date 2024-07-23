#include <stdio.h>
#include <string.h>

void decryptSubstitutionCipher(char ciphertext[], char key[]) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int index = ciphertext[i] - 'A';
            printf("%c", key[index]);
        } else {
            printf("%c", ciphertext[i]);         }
    }
    printf("\n");
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;e26)e‡.)e‡);806*;the†8¶60))85;;]e*;:‡*the†3 (he)5*†;46(;he*96*?;e)*‡(;the5);5*†2:*‡(;4956*2(5*—4)8¶8* ;40692the);)6†e)4‡‡;1(‡9;the081;8:8‡1;the†85;4)the5†528e06*81 (‡9;the;(he;4(‡?34;he)4‡;161;:188;‡?;";

    char key[] = "ETAOINSHRDLCUMWFGYPBVKJXQZ"; 
    decryptSubstitutionCipher(ciphertext, key);

    return 0;
}
