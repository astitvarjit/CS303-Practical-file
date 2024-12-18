#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 

struct List {
    float list[MAX];
    int length;
} fl;

int menu(void);         
void create(void);       
void insert(float value, int pos);     
void delet(int pos);       
void find(float value);        
void display(void);       
bool islistfull(void);  
bool islistempty(void);         

int menu() {
    int ch;
    printf("\n1. Create\n2. Insert\n3. Delete\n4. Count\n5. Find\n6. Display\n7.Exit\n\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void create(void) {
    float value;
    fl.length = 0;  
    while (true) {
        if (islistfull()) {
            printf("List is full. Cannot add more elements.\n");
            break;
        }
        printf("Enter value: ");
        scanf("%f", &value);
        fl.list[fl.length++] = value;
        printf("To insert another value press 1, otherwise 0: ");
        int flag;
        scanf("%d", &flag);
        if (flag != 1) break;
    }
}

void display(void) {
    if (islistempty()) {
        printf("List is empty.\n");
        return;
    }
    for (int i = 0; i < fl.length; i++) {
        printf("Element %d: %.2f\n", i + 1, fl.list[i]);
    }
}

void insert(float value, int pos) {
    if (pos <= 0 || pos > fl.length + 1) {
        printf("Invalid position. Valid positions: 1 to %d.\n", fl.length + 1);
        return;
    }
    if (islistfull()) {
        printf("List is full. Cannot insert the value.\n");
        return;
    }
    for (int i = fl.length; i >= pos - 1; i--) {
        fl.list[i + 1] = fl.list[i];
    }
    fl.list[pos - 1] = value;
    fl.length++;
}

void delet(int pos) {
    if (pos <= 0 || pos > fl.length) {
        printf("Invalid position. Valid positions: 1 to %d.\n", fl.length);
        return;
    }
    for (int i = pos - 1; i < fl.length - 1; i++) {
        fl.list[i] = fl.list[i + 1];
    }
    fl.length--;
}

void find(float value) {
    for (int i = 0; i < fl.length; i++) {
        if (fl.list[i] == value) {
            printf("%.2f exists at position %d.\n", value, i + 1);
            return;
        }
    }
    printf("Value not found.\n");
}

bool islistfull(void) {
    return fl.length == MAX;
}

bool islistempty(void) {
    return fl.length == 0;
}

int main() {
    int ch, pos;
    float value;
    fl.length = 0;  // Initialize the list length
    while (1) {
        ch = menu();
        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%f", &value);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert(value, pos);
                break;
            case 3:
                printf("Enter the position of the value to delete: ");
                scanf("%d", &pos);
                delet(pos);
                break;
            case 4:
                printf("Number of elements in the list: %d\n", fl.length);
                break;
            case 5:
                printf("Enter the value to search: ");
                scanf("%f", &value);
                find(value);
                break;
            case 6:
                display();
                break;
            case 7:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
