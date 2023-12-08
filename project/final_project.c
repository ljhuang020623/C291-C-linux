#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MEMORY 5
#define MAX_WORD_LENGTH 100

// Structure for a doubly-linked list node
struct DoublyLinkedList {
    char *word;
    int frequency; // Used in MODE 2
    struct DoublyLinkedList *next;
    struct DoublyLinkedList *prev;
};

int numberOfWords = 0;
int mode; // Input mode
struct DoublyLinkedList *head = NULL;
struct DoublyLinkedList *tail = NULL;

// Function to add a word to memory (MODE 1)
void addwordToMemory_Mode1(char *word) {
    // Check if the word already exists and bring it to the start
    struct DoublyLinkedList *current = head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Word found in memory, move it to the start
            if (current != head) {
                current->prev->next = current->next;
                if (current != tail) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
                current->prev = NULL;
                current->next = head;
                head->prev = current;
                head = current;
            }
            return;
        }
        current = current->next;
    }

    // If the word doesn't exist and memory is not full, add it to the start
    if (numberOfWords < MEMORY) {
        struct DoublyLinkedList *newNode = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
        newNode->word = strdup(word);
        newNode->frequency = 0;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        numberOfWords++;
    } else { // Memory is full, remove the end node and add the new word to start
        struct DoublyLinkedList *lastNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(lastNode->word);
        free(lastNode);
        struct DoublyLinkedList *newNode = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
        newNode->word = strdup(word);
        newNode->frequency = 0;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }
}
// Function to add a word to memory (MODE 2)
void addwordToMemory_Mode2(char *word) {
    struct DoublyLinkedList *current = head;
    struct DoublyLinkedList *prev = NULL;

    // Search for the word in the list
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            // Word found, increment its frequency
            current->frequency++;

            // Move the word to the appropriate position in the list based on frequency
            while (prev != NULL && current->frequency > prev->frequency) {
                prev = prev->prev;
            }

            // Remove the word from its current position
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }

            // Insert the word into the new position
            if (prev != NULL) {
                current->prev = prev;
                current->next = prev->next;
                prev->next = current;
                if (current->next != NULL) {
                    current->next->prev = current;
                }
            } else {
                current->prev = NULL;
                current->next = head;
                head->prev = current;
                head = current;
            }

            return;
        }
        prev = current;
        current = current->next;
    }

    // If the word doesn't exist and memory is not full, add it to the start
    if (numberOfWords < MEMORY) {
        struct DoublyLinkedList *newNode = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
        newNode->word = strdup(word);
        newNode->frequency = 1;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
        numberOfWords++;
    } else { // Memory is full, remove the end node and add the new word to start
        struct DoublyLinkedList *lastNode = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(lastNode->word);
        free(lastNode);
        struct DoublyLinkedList *newNode = (struct DoublyLinkedList *)malloc(sizeof(struct DoublyLinkedList));
        newNode->word = strdup(word);
        newNode->frequency = 1;
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
    }
}


// Function to print the memory array
void printMemoryArray() {
    struct DoublyLinkedList *current = head;
    printf("[");
    while (current != NULL) {
        printf("\"%s\"", current->word);
        current = current->next;
        if (current != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

// Function to search for a word in the memory array
bool searchwordInMemoryArray(char *targetWord) {
    struct DoublyLinkedList *current = head;
    while (current != NULL) {
        if (strcmp(current->word, targetWord) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    printf("Enter the mode (1 or 2): ");
    scanf("%d", &mode);
    
    if (mode != 1 && mode != 2) {
        printf("Invalid mode. Please enter 1 for MODE 1 or 2 for MODE 2.\n");
        return 1;
    }

    int numWords;
    printf("Enter number of words to be stored in the array: ");
    scanf("%d", &numWords);

    if (numWords <= 0) {
        printf("Invalid number of words. Please enter a positive number.\n");
        return 1;
    }

    getchar(); // Clear newline character from the input buffer

    for (int i = 1; i <= numWords; i++) {
        char word[MAX_WORD_LENGTH];
        printf("Enter word %d: ", i);
        fgets(word, sizeof(word), stdin);
        word[strcspn(word, "\n")] = '\0'; // Remove trailing newline character
        
        if (mode == 1) {
            addwordToMemory_Mode1(word);
        } else if (mode == 2) {
            addwordToMemory_Mode2(word);
        }

        printf("Memory Array: ");
        printMemoryArray();
    }

    return 0;
}

