#include <stdio.h>
int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;               
    }
    return reversed;
}
int main() {
    int number, reversed;
    printf("Enter a number: ");
    scanf("%d", &number);
    reversed = reverseNumber(number);
    printf("Reversed number: %d\n", reversed);
    return 0;
}

