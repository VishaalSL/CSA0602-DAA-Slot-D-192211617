#include <stdio.h>
#include <stdbool.h>
void sieveOfEratosthenes(int limit) {
    bool prime[limit + 1];
    int i, p;
    for (i = 0; i <= limit; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (p = 2; p * p <= limit; p++) {
        if (prime[p] == true) {
            for (i = p * p; i <= limit; i += p) {
                prime[i] = false;
            }
        }
    }
    printf("Prime numbers up to %d are:\n", limit);
    for (p = 2; p <= limit; p++) {
        if (prime[p]) {
            printf("%d ", p);
        }
    }
    printf("\n");
}
int main() {
    int limit;
    printf("Enter the upper limit to generate prime numbers: ");
    scanf("%d", &limit);
    if (limit < 2) {
        printf("There are no prime numbers less than 2.\n");
        return 0;
    }
    sieveOfEratosthenes(limit);
    return 0;
}
