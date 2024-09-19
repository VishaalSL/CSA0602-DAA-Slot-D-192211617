#include <stdio.h>
#include <limits.h>
#define MAX 100
int optimalBST(int freq[], int n) {
    int cost[MAX][MAX];
    int sum[MAX][MAX];
    int i, j, k, l;
    for (i = 0; i < n; i++) {
        sum[i][i] = freq[i];
        for (j = i + 1; j < n; j++) {
            sum[i][j] = sum[i][j - 1] + freq[j];
        }
    }
    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
    }
    for (l = 2; l <= n; l++) {
        for (i = 0; i <= n - l; i++) {
            j = i + l - 1;
            cost[i][j] = INT_MAX;
            for (k = i; k <= j; k++) {
                int q = (k > i ? cost[i][k - 1] : 0) + 
                        (k < j ? cost[k + 1][j] : 0) + 
                        sum[i][j];
                if (q < cost[i][j]) {
                    cost[i][j] = q;
                }
            }
        }
    }
    return cost[0][n - 1];
}
int main() {
    int n, i;
    int freq[MAX];
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    printf("Enter the frequencies of the keys:\n");
    for (i = 0; i < n; i++) {
        printf("Frequency of key %d: ", i + 1);
        scanf("%d", &freq[i]);
    }
    int minCost = optimalBST(freq, n);
    printf("The minimum cost of the optimal BST is: %d\n", minCost);
    return 0;
}

