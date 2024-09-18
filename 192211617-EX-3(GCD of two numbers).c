#include <stdio.h>
int findGCD(int a, int b) {
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
int main() {
    int num1, num2, gcd;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    gcd = findGCD(num1, num2);
    printf("GCD of %d and %d is %d.\n", num1, num2, gcd);
    return 0;
}

