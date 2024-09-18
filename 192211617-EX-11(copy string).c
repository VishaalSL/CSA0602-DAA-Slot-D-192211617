#include <stdio.h>
#include <string.h>
void copyString(char *destination, const char *source) {
    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; 
}
int main() {
    char source[] = "Hello, World!";
    char destination[50];
    copyString(destination, source);
    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);
    return 0;
}

