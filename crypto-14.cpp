#include <iostream>
#include <string>
#include <vector>

// Function to encrypt plaintext using the key stream
std::string encryptVigenereOneTimePad(const std::string& plaintext, const std::vector<int>& keyStream) {
    std::string ciphertext;
    int len = plaintext.length();
    for (int i = 0; i < len; ++i) {
        char p = plaintext[i];
        int shift = keyStream[i % len]; // Repeating key stream

        if (std::isalpha(p)) {
            char base = (std::isupper(p)) ? 'A' : 'a';
            char encryptedChar = ((p - base + shift) % 26) + base;
            ciphertext += encryptedChar;
        } else {
            // Non-alphabetic characters remain unchanged
            ciphertext += p;
        }
    }
    return ciphertext;
}

int main() {
    const std::string plaintext = "send more money";
    const std::vector<int> keyStream = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};

    // Encrypt
    std::string ciphertext = encryptVigenereOneTimePad(plaintext, keyStream);
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}
