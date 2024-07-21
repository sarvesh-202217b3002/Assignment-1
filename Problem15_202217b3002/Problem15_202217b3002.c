#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List node
struct node {
    char* key;
    char* value;
    struct node* next;
};

// Function to set the node values
void setNode(struct node* node, const char* key, const char* value) {
    node->key = strdup(key);   // Duplicate key string
    node->value = strdup(value); // Duplicate value string
    node->next = NULL;
}

// HashMap structure
struct hashMap {
    int numOfElements;
    int capacity;
    struct node** arr;
};

// Function to initialize the hash map
void initializeHashMap(struct hashMap* mp) {
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node**)malloc(sizeof(struct node*) * mp->capacity);
    for (int i = 0; i < mp->capacity; i++) {
        mp->arr[i] = NULL;
    }
}

// Hash function
int hashFunction(struct hashMap* mp, const char* key) {
    int sum = 0;
    int factor = 31;
    for (int i = 0; i < strlen(key); i++) {
        sum = ((sum % mp->capacity) + (((int)key[i]) * factor) % mp->capacity) % mp->capacity;
        factor = ((factor % __INT16_MAX__) * (31 % __INT16_MAX__)) % __INT16_MAX__;
    }
    return sum;
}

// Function to insert key-value pair
void insert(struct hashMap* mp, const char* key, const char* value) {
    int bucketIndex = hashFunction(mp, key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    setNode(newNode, key, value);
    if (mp->arr[bucketIndex] == NULL) {
        mp->arr[bucketIndex] = newNode;
    } else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

// Function to delete key-value pair
void delete(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* prevNode = NULL;
    struct node* currNode = mp->arr[bucketIndex];
    while (currNode != NULL) {
        if (strcmp(key, currNode->key) == 0) {
            if (currNode == mp->arr[bucketIndex]) {
                mp->arr[bucketIndex] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            free(currNode->key);
            free(currNode->value);
            free(currNode);
            mp->numOfElements--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

// Function to search for a value by key
char* search(struct hashMap* mp, const char* key) {
    int bucketIndex = hashFunction(mp, key);
    struct node* bucketHead = mp->arr[bucketIndex];
    while (bucketHead != NULL) {
        if (strcmp(key, bucketHead->key) == 0) {
            return bucketHead->value;
        }
        bucketHead = bucketHead->next;
    }
    return "Oops! No data found.\n";
}

// Driver code
int main() {
    struct hashMap* mp = (struct hashMap*)malloc(sizeof(struct hashMap));
    initializeHashMap(mp);

    int choice;
    char key[100];
    char value[100];
    
    while (1) {
        printf("\nHash Table Operations:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter key: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline character

                printf("Enter value: ");
                fgets(value, sizeof(value), stdin);
                value[strcspn(value, "\n")] = '\0'; // Remove newline character

                insert(mp, key, value);
                printf("Inserted (%s, %s)\n", key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline character

                printf("Value: %s\n", search(mp, key));
                break;

            case 3:
                printf("Enter key to delete: ");
                fgets(key, sizeof(key), stdin);
                key[strcspn(key, "\n")] = '\0'; // Remove newline character

                delete(mp, key);
                printf("Deleted key: %s\n", key);
                break;

            case 4:
                // Free the memory for all nodes and hash map
                for (int i = 0; i < mp->capacity; i++) {
                    struct node* currNode = mp->arr[i];
                    while (currNode != NULL) {
                        struct node* nextNode = currNode->next;
                        free(currNode->key);
                        free(currNode->value);
                        free(currNode);
                        currNode = nextNode;
                    }
                }
                free(mp->arr);
                free(mp);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
