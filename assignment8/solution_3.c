#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* replaceAll(const char* string, const char* target, const char* replacement) {
    char* result;
    int i, cnt = 0;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);

    for (i = 0; string[i] != '\0'; i++) {
        if (strstr(&string[i], target) == &string[i]) {
            cnt++;
            i += targetLen - 1;
        }
    }

    result = (char*)malloc(i + cnt * (replacementLen - targetLen) + 1);
    i = 0;
    while (*string) {
        if (strstr(string, target) == string) {
            strcpy(&result[i], replacement);
            i += replacementLen;
            string += targetLen;
        } else {
            result[i++] = *string++;
        }
    }

    result[i] = '\0';
    return result;
}

int main() {
    char str[1000], tgt[1000], repl[1000];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';

    printf("Enter the target: ");
    fgets(tgt, sizeof(tgt), stdin);
    tgt[strlen(tgt)-1] = '\0';

    printf("Enter replacement: ");
    fgets(repl, sizeof(repl), stdin);
    repl[strlen(repl)-1] = '\0';

    char* res = replaceAll(str, tgt, repl);
    printf("Output: %s\n", res);
    free(res);

    return 0;
}

