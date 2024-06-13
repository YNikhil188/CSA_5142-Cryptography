#include <stdio.h>
#include <string.h>
void print_hex(unsigned char *data, int len) {
    for(int i = 0; i < len; i++)
        printf("%02X", data[i]);
    printf("\n");
}
void left_shift(unsigned char *input, unsigned char *output, int len) {
    int carry = 0;
    for(int i = len - 1; i >= 0; i--) {
        output[i] = input[i] << 1 | carry;
        carry = (input[i] & 0x80) ? 1 : 0;
    }
}
void xor_with_constant(unsigned char *input, int len, unsigned char constant) {
    input[len - 1] ^= constant;
}
void generate_subkeys(unsigned char *key, int block_size, unsigned char *K1, unsigned char *K2) {
    unsigned char L[16] = {0}; 
    unsigned char Z[16] = {0}; 

    memcpy(L, Z, block_size / 8);

    printf("L: ");
    print_hex(L, block_size / 8);

    left_shift(L, K1, block_size / 8);
    if (L[0] & 0x80) {
        if (block_size == 128) {
            xor_with_constant(K1, block_size / 8, 0x87);
        } else if (block_size == 64) {
            xor_with_constant(K1, block_size / 8, 0x1B);
        }
    }

    printf("K1: ");
    print_hex(K1, block_size / 8);

    left_shift(K1, K2, block_size / 8);
    if (K1[0] & 0x80) {
        if (block_size == 128) {
            xor_with_constant(K2, block_size / 8, 0x87);
        } else if (block_size == 64) {
            xor_with_constant(K2, block_size / 8, 0x1B);
        }
    }
    printf("K2: ");
    print_hex(K2, block_size / 8);
}
int main() {
    unsigned char key[16] = {0};
    unsigned char K1[16] = {0};
    unsigned char K2[16] = {0};
    int block_size = 128; 
    generate_subkeys(key, block_size, K1, K2);
    return 0;
}
