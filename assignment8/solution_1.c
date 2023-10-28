#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char ** myTokenizer(char * str, const char *delim) {
    int i, j, k, tokenCount = 0, delimLen = strlen(delim);
    char **tokens, *token;

    tokens = malloc(sizeof(char*) * (strlen(str) + 1));

    for (i = 0; i < strlen(str);) {
        while (str[i] && strncasecmp(&str[i], delim, delimLen) == 0) {
            i += delimLen;
        }
        j = i;
        while (str[j] && strncasecmp(&str[j], delim, delimLen) != 0) {
            j++;
        }
        if (j != i) {
            token = malloc(j - i + 1);
            strncpy(token, &str[i], j - i);
            token[j - i] = '\0';
            tokens[tokenCount++] = token;
        }
        i = j;
    }

    if (tokenCount == 0) {
        free(tokens);
        return NULL;
    }

    return tokens;
}

int main() {
    char str[1000], delim[1000];
    char **tokens;

    printf("Input the string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Input the delimiter: ");
    fgets(delim, sizeof(delim), stdin);
    delim[strcspn(delim, "\n")] = '\0';

    tokens = myTokenizer(str, delim);
    if (tokens) {
        for (int i = 0; tokens[i]; i++) {
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }
        free(tokens);
    } else {
        printf("NULL\n");
    }

    return 0;
}

