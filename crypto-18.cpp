#include <stdio.h>
#include <stdint.h>

void generate_subkeys(const uint64_t key, uint64_t subkeys[16]) {
    // Implement the subkey generation with the specified bit positions
    // This is a placeholder for the actual subkey generation logic
}

int main() {
    uint64_t key = 0x133457799BBCDFF1; // Replace with your actual key
    uint64_t subkeys[16];

    generate_subkeys(key, subkeys);

    for (int i = 0; i < 16; i++) {
        printf("Subkey %d: %llx\n", i + 1, subkeys[i]);
    }

    return 0;
}
