#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MATRIX_SIZE 5

void generatePlayfairMatrix(char* keyword, char matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    int seen[26] = {0};
    int index = 0;
    int row, col;

    
    for (int i = 0; keyword[i] != '\0'; i++) {
        char ch = toupper(keyword[i]);
        if (ch == 'J') ch = 'I';
        if (!seen[ch - 'A']) {
            row = index / MATRIX_SIZE;
            col = index % MATRIX_SIZE;
            matrix[row][col] = ch;
            seen[ch - 'A'] = 1;
            index++;
        }
    }

   
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue;
        if (!seen[ch - 'A']) {
            row = index / MATRIX_SIZE;
            col = index % MATRIX_SIZE;
            matrix[row][col] = ch;
            seen[ch - 'A'] = 1;
            index++;
        }
    }
}

void printMatrix(char matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}



int main() {
    char keyword[] = "saveetha";
    char matrix[MATRIX_SIZE][MATRIX_SIZE];

    generatePlayfairMatrix(keyword, matrix);
    printf("Playfair Matrix:\n");
    printMatrix(matrix);



    return 0;
}
