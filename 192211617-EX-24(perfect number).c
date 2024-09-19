#include <stdio.h>
int isPerfectNumber(int num) {
    int sum = 0;
    int i;
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return (sum == num);
}
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number > 0) {
        if (isPerfectNumber(number)) {
            printf("%d is a perfect number.\n", number);
        } else {
            printf("%d is not a perfect number.\n", number);
        }
    } else {
        printf("Please enter a positive number.\n");
    }
    return 0;
}

