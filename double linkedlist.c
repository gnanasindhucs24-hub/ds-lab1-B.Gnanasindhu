#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Create new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", data);
}

// Insert at end
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Inserted %d at end.\n", data);
}

// Insert after given value
void insertAfter(int key, int data) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key %d not found!\n", key);
        return;
    }

    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    printf("Inserted %d after %d.\n", data, key);
}

// Delete node by value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;

    // If head is deleted
    if (temp->data == key) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        printf("Deleted %d.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Key not found!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    temp->prev->next = temp->next;

    free(temp);
    printf("Deleted %d.\n", key);
}

// Display forward
void displayForward() {
    struct Node *temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}





// MAIN
int main() {
    int choice, data, key;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Value\n");
        printf("4. Delete\n");
        printf("5. Display Forward\n");

        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &data);
                insertAfter(key, data);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &key);
                deleteNode(key);
                break;

            case 5:
                displayForward();
                break;

            case 6:
                printf("Exiting\n");

                break;
            default:
                printf("�nvalid choice\n");
                break;


        }
    }

    return 0;
}
