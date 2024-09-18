#include <stdio.h>
#define N 2 
void printMatrix(int mat[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
void strassenMatrixMultiplication(int A[N][N], int B[N][N], int C[N][N]) {
    int M1, M2, M3, M4, M5, M6, M7;
    int temp1[N][N], temp2[N][N];
    int i, j;
    temp1[0][0] = A[0][0] + A[1][1];
    temp1[0][1] = A[0][1] + A[1][1];
    temp2[0][0] = B[0][0] + B[1][1];
    temp2[0][1] = B[0][1] + B[1][1];
    M1 = temp1[0][0] * temp2[0][0] + temp1[0][1] * temp2[0][1];
    temp1[0][0] = A[1][0] + A[1][1];
    M2 = temp1[0][0] * B[0][0] + B[1][0] * B[0][1];
    temp2[0][0] = B[0][1] - B[1][1];
    M3 = A[0][0] * temp2[0][0];
    temp2[0][0] = B[1][0] - B[0][0];
    M4 = A[1][1] * temp2[0][0];
    temp1[0][0] = A[0][0] + A[0][1];
    M5 = temp1[0][0] * B[1][1];
    temp1[0][0] = A[1][0] - A[0][0];
    temp2[0][0] = B[0][0] + B[0][1];
    M6 = temp1[0][0] * temp2[0][0];
    temp1[0][0] = A[0][1] - A[1][1];
    temp2[0][0] = B[1][0] + B[1][1];
    M7 = temp1[0][0] * temp2[0][0];
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}
int main() {
    int A[N][N] = { {1, 2}, {3, 4} };
    int B[N][N] = { {5, 6}, {7, 8} };
    int C[N][N];
    printf("Matrix A:\n");
    printMatrix(A);
    printf("Matrix B:\n");
    printMatrix(B);
    strassenMatrixMultiplication(A, B, C);
    printf("Resultant Matrix C:\n");
    printMatrix(C);
    return 0;
}

