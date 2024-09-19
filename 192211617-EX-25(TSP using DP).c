#include <stdio.h>
#include <limits.h>
#include <string.h>
#define INF INT_MAX
#define MAX_CITIES 20
int tsp(int graph[MAX_CITIES][MAX_CITIES], int n) {
    int dp[1 << MAX_CITIES][MAX_CITIES];
    int i, j, k, mask;
    memset(dp, INF, sizeof(dp));
    dp[1][0] = 0;
    for (mask = 1; mask < (1 << n); mask += 2) {
        for (i = 1; i < n; i++) {
            if (mask & (1 << i)) {
                for (j = 0; j < n; j++) {
                    if (mask & (1 << j) && i != j) {
                        dp[mask][i] = (dp[mask][i] < dp[mask ^ (1 << i)][j] + graph[j][i]) ? dp[mask][i] : dp[mask ^ (1 << i)][j] + graph[j][i];
                    }
                }
            }
        }
    }
    int result = INF;
    for (i = 1; i < n; i++) {
        result = (result < dp[(1 << n) - 1][i] + graph[i][0]) ? result : dp[(1 << n) - 1][i] + graph[i][0];
    }
    return result;
}
int main() {
    int n, i, j;
    int graph[MAX_CITIES][MAX_CITIES];
    printf("Enter the number of cities (max %d): ", MAX_CITIES);
    scanf("%d", &n);
    printf("Enter the cost matrix (adjacency matrix):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int result = tsp(graph, n);
    printf("The minimum cost of the TSP tour is: %d\n", result);
    return 0;
}
