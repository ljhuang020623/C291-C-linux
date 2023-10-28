#include <stdio.h>
#include <string.h>

int indexOf(char * haystack, char * needle, int fromIndex) {
    char *result = strstr(haystack + fromIndex, needle);
    if (result) {
        return result - haystack;
    }
    return -1;
}

int main() {
    char haystack[1000], needle[1000];
    int fromIndex, index;

    printf("Haystack: ");
    fgets(haystack, sizeof(haystack), stdin);
    haystack[strcspn(haystack, "\n")] = '\0';

    printf("Needle: ");
    fgets(needle, sizeof(needle), stdin);
    needle[strcspn(needle, "\n")] = '\0';

    printf("From Index: ");
    scanf("%d", &fromIndex);

    index = indexOf(haystack, needle, fromIndex);
    if (index != -1) {
        printf("The needle is found at index %d.\n", index);
    } else {
        printf("The needle cannot be found in the haystack.\n");
    }

    return 0;
}

