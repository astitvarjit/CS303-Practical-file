#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *prev;
    struct node *next;
    int data;
};
void insertionFirst();
void insertionLast();
void insertionLoc();
void deleteFirst();
void deleteLast();
void deleteLoc();
void printList();
void searchList();
struct node *head = NULL;
int main() {
    int choice = 0;
    while (choice != 9) {
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at last\n");
        printf("3. Insert at any random location\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from last\n");
        printf("6. Delete the node after the given data\n");
        printf("7. Search\n");
        printf("8. Show\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertionFirst();
                break;
            case 2:
                insertionLast();
                break;
            case 3:
                insertionLoc();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                deleteLoc();
                break;
            case 7:
                searchList();
                break;
            case 8:
                printList();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}
void insertionFirst() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    if (ptr == NULL) {
        printf("\nOVERFLOW!!!");
    } else {
        printf("\nEnter value to insert: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->prev = NULL;
        if (head == NULL) {
            ptr->next = NULL;
            head = ptr;
        } else {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        printf("\nNode inserted successfully.\n");
    }
}
void insertionLast() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item;
    if (ptr == NULL) {
        printf("\nOVERFLOW!!!");
    } else {
        printf("\nEnter value to insert: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL) {
            ptr->next = NULL;
            ptr->prev = NULL;
            head = ptr;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
        printf("\nNode inserted successfully.\n");
    }
}
void insertionLoc() {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int item, loc, i;
    if (ptr == NULL) {
        printf("\nOVERFLOW!!!");
    } else {
        printf("\nEnter the location: ");
        scanf("%d", &loc);
        printf("Enter value: ");
        scanf("%d", &item);
        ptr->data = item;

        struct node *temp = head;
        for (i = 0; i < loc - 1; i++) {
            if (temp == NULL) {
                printf("\nThere are less than %d elements.\n", loc);
                return;
            }
            temp = temp->next;
        }
        ptr->next = temp->next;
        ptr->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        temp->next = ptr;
        printf("\nNode inserted successfully.\n");
    }
}
void deleteFirst() {
    if (head == NULL) {
        printf("\nUNDERFLOW!!!");
    } else {
        struct node *ptr = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        free(ptr);
        printf("\nNode deleted successfully.\n");
    }
}
void deleteLast() {
    if (head == NULL) {
        printf("\nUNDERFLOW!!!");
    } else {
        struct node *ptr = head;
        if (head->next == NULL) {
            head = NULL;
        } else {
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->prev->next = NULL;
        }
        free(ptr);
        printf("\nNode deleted successfully.\n");
    }
}
void deleteLoc() {
    int val;
    printf("\nEnter the data after which the node is to be deleted: ");
    scanf("%d", &val);
    struct node *ptr = head;
    while (ptr != NULL && ptr->data != val) {
        ptr = ptr->next;
    }
    if (ptr == NULL || ptr->next == NULL) {
        printf("\nCan't delete. Node not found or no next node exists.\n");
    } else {
        struct node *temp = ptr->next;
        ptr->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = ptr;
        }
        free(temp);
        printf("\nNode deleted successfully.\n");
    }
}
void printList() {
    struct node *ptr = head;
    printf("\nThe Doubly Linked List is: START ⇄ ");
    while (ptr != NULL) {
        printf("%d ⇄ ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void searchList() {
    int item, pos = 1, found = 0;
    printf("\nEnter the item to search: ");
    scanf("%d", &item);
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->data == item) {
            printf("\nItem %d found at position %d.\n", item, pos);
            found = 1;
            break;
        }
        ptr = ptr->next;
        pos++;
    }
    if (!found) {
        printf("\nItem %d not found in the list.\n", item);
    }
}
