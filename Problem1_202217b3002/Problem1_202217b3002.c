#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;  // Initialize the array and size of the list

void main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create\n2. Delete\n3. Search\n4. Insert\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter the correct choice:\n");
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &g); // Added space before %c to consume any leftover newline character
    } while (g == 'y' || g == 'Y');
}

void create() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("List can have a maximum of %d elements.\n", MAX);
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (pos >= n || pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;

    printf("Elements after deletion:\n");
    display();
}

void search() {
    int e, found = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &e);

    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Value is in the %d position.\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Value %d is not in the list.\n", e);
    }
}

void insert() {
    if (n >= MAX) {
        printf("List is full.\n");
        return;
    }

    int pos, p;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos > n || pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);
    b[pos] = p;
    n++;

    printf("The list after insertion:\n");
    display();
}

void display() {
    printf("The elements of the list ADT are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", b[i]);
    }
}
