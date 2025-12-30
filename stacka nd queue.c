#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create list
struct node* create(struct node *head) {
    struct node *newNode, *temp;
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Display
void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Sort list
struct node* sort(struct node *head) {
    struct node *i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return head;
}

// Reverse list
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Concatenate two lists
struct node* concatenate(struct node *h1, struct node *h2) {
    struct node *temp = h1;
    if (h1 == NULL)
        return h2;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = h2;
    return h1;
}

int main() {
    struct node *head1 = NULL, *head2 = NULL;

    printf("Create List 1\n");
    head1 = create(head1);
    printf("Create List 2\n");
    head2 = create(head2);

    printf("\nSorted List 1:\n");
    head1 = sort(head1);
    display(head1);

    printf("\nReversed List 1:\n");
    head1 = reverse(head1);
    display(head1);

    printf("\nConcatenated List:\n");
    head1 = concatenate(head1, head2);
    display(head1);

    return 0;
}
