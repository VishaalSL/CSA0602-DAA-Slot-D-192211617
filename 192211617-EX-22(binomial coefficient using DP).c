#include <stdio.h>
#include <stdlib.h>
int binomialCoefficient(int n, int k) {
    int **dp;
    int i, j;
    dp = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((k + 1) * sizeof(int));
    }
    for (i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (j = 1; j <= k; j++) {
        dp[j][j] = 1; 
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j < k && j < i; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    int result = dp[n][k];
    for (i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}
int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    if (k > n || k < 0) {
        printf("Invalid values: k should be between 0 and n.\n");
        return 1;
    }
    int result = binomialCoefficient(n, k);
    printf("C(%d, %d) = %d\n", n, k, result);
    return 0;
}

