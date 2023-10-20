#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WORD_SIZE 100
char** tokenize(const char* str) {  // use 'const' to indicate that the original string won't be modified
    char* tempStr = strdup(str);  // create a copy of the string
    char** tokens = malloc(MAX_WORD_SIZE * sizeof(char*));
    if (tokens == NULL) {
        // Handle memory allocation failure
        free(tempStr);
        return NULL;
    }

    int index = 0;
    char* token = strtok(tempStr, " ");
    while (token != NULL && index < MAX_WORD_SIZE - 1) {  // ensure we don't go beyond the allocated space
        tokens[index] = strdup(token);
        index++;
        token = strtok(NULL, " ");
    }
    tokens[index] = NULL; // mark the end of the array of tokens

    free(tempStr);  // free the temporary string
    return tokens;
}


char** getUniqueWords(char** tokens) {
    char** uniqueWords = malloc(MAX_WORD_SIZE * sizeof(char*));
    int count = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(tokens[i], uniqueWords[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            uniqueWords[count] = strdup(tokens[i]);
            count++;
        }
    }
    uniqueWords[count] = NULL; // mark the end of the array
    return uniqueWords;
}

void freeWords(char** words) {
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}

char** getStudentAnswers(const char* questions[], int n, int max_len) {
    char** answers = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        answers[i] = malloc(max_len * sizeof(char));
        printf("Question %d: %s\n", i + 1, questions[i]);
        fgets(answers[i], max_len, stdin);
        strtok(answers[i], "\n");  // Remove newline character
    }
    return answers;
}

int** ans2Vectors(char* instructor_answer, char* student_answer) {
    char* instructor_copy = strdup(instructor_answer);
    char* student_copy = strdup(student_answer);

    for (int i = 0; instructor_copy[i]; i++) {
        instructor_copy[i] = tolower(instructor_copy[i]);
    }
    for (int i = 0; student_copy[i]; i++) {
        student_copy[i] = tolower(student_copy[i]);
    }

    char** instructor_tokens = tokenize(instructor_copy);
    char** student_tokens = tokenize(student_copy);

    int instructor_tokens_count = 0;
    for (; instructor_tokens[instructor_tokens_count] != NULL; instructor_tokens_count++);

    int student_tokens_count = 0;
    for (; student_tokens[student_tokens_count] != NULL; student_tokens_count++);

    char** all_tokens = malloc(sizeof(char*) * (instructor_tokens_count + student_tokens_count + 1));
    int total_tokens = 0;
    for (int i = 0; i < instructor_tokens_count; i++) {
        all_tokens[total_tokens++] = instructor_tokens[i];
    }
    for (int i = 0; i < student_tokens_count; i++) {
        all_tokens[total_tokens++] = student_tokens[i];
    }
    all_tokens[total_tokens] = NULL;

    char** dictionary = getUniqueWords(all_tokens);
    int U = 0;
    for (; dictionary[U] != NULL; U++);

    int* instructor_vector = calloc(U, sizeof(int));
    int* student_vector = calloc(U, sizeof(int));

    for (int i = 0; i < U; i++) {
        for (int j = 0; j < instructor_tokens_count; j++) {
            if (strcmp(dictionary[i], instructor_tokens[j]) == 0) {
                instructor_vector[i]++;
            }
        }
        for (int j = 0; j < student_tokens_count; j++) {
            if (strcmp(dictionary[i], student_tokens[j]) == 0) {
                student_vector[i]++;
            }
        }
    }

    freeWords(instructor_tokens);
    freeWords(student_tokens);
    free(all_tokens);
    freeWords(dictionary);
    free(instructor_copy);
    free(student_copy);

    int** vectors = malloc(2 * sizeof(int*));
    vectors[0] = instructor_vector;
    vectors[1] = student_vector;
    return vectors;
}

double cosineSimilarity(char* instructor_answer, char* student_answer) {
    int** vectors = ans2Vectors(instructor_answer, student_answer);
    int* A = vectors[0];
    int* B = vectors[1];

    double dot_product = 0;
    double mag_A = 0;
    double mag_B = 0;

    char** dictionary = getUniqueWords(tokenize(instructor_answer));
    int U = 0;
    for (; dictionary[U] != NULL; U++);

    for (int i = 0; i < U; i++) {
        dot_product += A[i] * B[i];
        mag_A += A[i] * A[i];
        mag_B += B[i] * B[i];
    }

    if (sqrt(mag_A) == 0 || sqrt(mag_B) == 0) {
        free(A);
        free(B);
        free(vectors);
        freeWords(dictionary);
        return 0; 
    }

    double similarity = dot_product / (sqrt(mag_A) * sqrt(mag_B));
    if(similarity > 1) similarity = 1;
    if(similarity < 0) similarity = 0;

    free(A);
    free(B);
    free(vectors);
    freeWords(dictionary);

    return similarity;
}

int main(void) {
    const char* questions[] = {
        "What are local variables?",
        "What is an identifier?",
        "What is recursion?",
        "What is a pointer?",
        "What is the purpose of applying static to a local array?"
    };
    const char* instructor_answers[] = {
        "Variables defined in function definition are local variables. They can be accessed only in that function scope.",
        "Identifiers are user defined names given to variables, functions and arrays.",
        "A function calling itself again and again to compute a value is referred to as recursive function or recursion. Recursion is useful for branching processes and is effective where terms are generated successively to compute a value.",
        "A pointer is a variable that stores the memory address of another variable as its value.",
        "By making a local array definition static the array is not created and initialized every time the function is called and it is not destroyed every time the function is exited. Also, the execution time is reduced."
    };
    int n = sizeof(questions) / sizeof(questions[0]);
    char** student_answers = getStudentAnswers(questions, n, 500);

    double total_marks = 0;
    for (int i = 0; i < n; i++) {
        double similarity = cosineSimilarity((char*)instructor_answers[i], student_answers[i]);
        double marks = similarity * 10;
        printf("Marks for question %d: %.2f\n", i + 1, marks);
        total_marks += marks;
    }
    printf("Total Marks: %.2f out of %d\n", total_marks, n * 10);

    for (int i = 0; i < n; i++) {
        free(student_answers[i]);
    }
    free(student_answers);

    return 0;
}

