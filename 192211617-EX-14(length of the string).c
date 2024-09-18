#include <stdio.h>
#include <string.h>
int findLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int length = findLength(str);
    printf("Length of the string is: %d\n", length);
    return 0;
}

