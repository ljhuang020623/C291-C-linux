#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 4
#define MAX_DOC_SIZE 1000
#define MAX_QUERY_SIZE 100
#define MAX_INTERSECTION_SIZE 1000

char* documents[N] = {
    "Located in Bloomington, Indiana, the campus of IU Bloomington is home to an extensive student life program. The university campus is 1937 acres, the largest of any university in Indiana. The university has a student count of over 45000. The campus is where a student takes classes, just like any other campus.",
    "The campus rests on a bed of Indiana limestone, along with the rest of Bloomington and southern Indiana. The Bryan house is the campus home of the university president. To a student and a faculty member alike, Indiana University has a campus that is rich with green space and historic buildings. Bloomington, Indiana is located in Southern Indiana.",
    "The Indiana Memorial Union in Bloomington is the second largest student union in the world. It features a student activities tower, which houses a variety of student organizations. The University campus is centered around this student union. The Campus has an extensive bus system.",
    "The Luddy School of Informatics, Computing, and Engineering is a school within Indiana University. A student can major in fields such as Informatics and Computer Science. The student count has grown greatly in the past few years, and Luddy Hall was built on Indiana University campus in 2018. Indiana University does not have a mascot. The university is known for its Sample Gates."
};

int string_frequency(const char* str, const char* target) {
    int count = 0;
    const char* tmp = str;
    while((tmp = strstr(tmp, target)) != NULL) {
        count++;
        tmp++;
    }
    return count;
}

char* to_lowercase(const char* str) {
    char* lowercase = strdup(str);
    for(int i = 0; lowercase[i]; i++) {
        lowercase[i] = tolower(lowercase[i]);
    }
    return lowercase;
}

char* searchEngine(char** documents, const char* query, int S) {
    int scores[MAX_QUERY_SIZE][N] = {0};
    int intersection[N] = {0};

    char* lower_query = to_lowercase(query);
    char* token = strtok(lower_query, " ");
    int term_index = 0;

    while (token) {
        for (int j = 0; j < N; j++) {
            char* lower_doc = to_lowercase(documents[j]);
            scores[term_index][j] = string_frequency(lower_doc, token);
            free(lower_doc);
        }
        token = strtok(NULL, " ");
        term_index++;
    }

    for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int i = 0; i < term_index; i++) {
            sum += scores[i][j];
        }
        intersection[j] = sum;
    }

    int max_index = 0;
    for (int j = 1; j < N; j++) {
        if (intersection[j] > intersection[max_index]) {
            max_index = j;
        }
    }

    free(lower_query);

    if (intersection[max_index] == 0) {
        return "No match found";
    }

    char* result = malloc(S + 1);
    strncpy(result, documents[max_index], S);
    result[S] = '\0';
    return result;
}

int main() {
    char query[MAX_QUERY_SIZE];
    int S;

    printf("Query: ");
    fgets(query, sizeof(query), stdin);
    query[strlen(query)-1] = '\0';  // Remove newline

    printf("Input number of characters to return: ");
    scanf("%d", &S);

    char* result = searchEngine(documents, query, S);
    printf("Output:\n%s\n", result);
    free(result);

    return 0;
}

