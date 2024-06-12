#include <stdio.h>
#include <string.h>

int main() {
    char key[5][5] = { {'M', 'F', 'H', 'I', 'K'}, {'U', 'N', 'O', 'P', 'Q'},
                       {'Z', 'V', 'W', 'X', 'Y'}, {'E', 'L', 'A', 'R', 'G'},
                       {'D', 'S', 'T', 'B', 'C'} };
    char msg[] = "MUSTSEEYOUOVERCADOGANWESTCOMINGATONCE", enc[100] = "";
    int len = strlen(msg), i, j, r1, c1, r2, c2;

    for (i = 0; i < len; i += 2) {
        if (msg[i] == msg[i + 1]) memmove(&msg[i + 1], &msg[i], len - i++);
        for (r1 = 0; r1 < 5; r1++) for (c1 = 0; c1 < 5; c1++) if (key[r1][c1] == msg[i]) break;
        for (r2 = 0; r2 < 5; r2++) for (c2 = 0; c2 < 5; c2++) if (key[r2][c2] == msg[i + 1]) break;
        enc[i] = r1 == r2 ? key[r1][(c1 + 1) % 5] : c1 == c2 ? key[(r1 + 1) % 5][c1] : key[r1][c2];
        enc[i + 1] = r1 == r2 ? key[r2][(c2 + 1) % 5] : c1 == c2 ? key[(r2 + 1) % 5][c2] : key[r2][c1];
    }
    printf("Encrypted: %s\n", enc);
return 0;
}