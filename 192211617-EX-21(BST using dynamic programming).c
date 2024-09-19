#include <stdio.h>
#include <limits.h>
void optimalBST(int freq[], int n) {
    int cost[n][n];
    int root[n][n];
    int i, j, k, r, length, sum;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cost[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }
    for (length = 2; length <= n; length++) {
        for (i = 0; i <= n - length; i++) {
            j = i + length - 1;
            cost[i][j] = INT_MAX;
            sum = 0;
            for (k = i; k <= j; k++) {
                sum += freq[k];
            }
            for (r = i; r <= j; r++) {
                int leftCost = (r > i) ? cost[i][r-1] : 0;
                int rightCost = (r < j) ? cost[r+1][j] : 0;
                int totalCost = leftCost + rightCost + sum;
                if (totalCost < cost[i][j]) {
                    cost[i][j] = totalCost;
                    root[i][j] = r;
                }
            }
        }
    }
     printf("Cost of the Optimal Binary Search Tree: %d\n", cost[0][n-1]);
    printf("Root table for the Optimal BST:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", root[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    int *freq;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    freq = (int *)malloc(n * sizeof(int));
    printf("Enter the frequencies of the keys:\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("Key %d: ", i + 1);
        scanf("%d", &freq[i]);
    }
    optimalBST(freq, n);
    free(freq);
    return 0;
}

