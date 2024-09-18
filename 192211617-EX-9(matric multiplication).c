#include <stdio.h>
#define MAX_SIZE 10
void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int rows2, int cols2) {
    int i, j, k;
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            result[i][j] = 0;
        }
    }
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols2; j++) {
            for (k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat1[MAX_SIZE][MAX_SIZE], mat2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;
    int i, j;
    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < cols1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < cols2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }
    multiplyMatrices(mat1, mat2, result, rows1, cols1, rows2, cols2);
    printf("Resultant matrix after multiplication:\n");
    displayMatrix(result, rows1, cols2);
    return 0;
}

