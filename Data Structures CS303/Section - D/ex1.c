#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;


treeNode* FindMin(treeNode *node) {
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}


treeNode* FindMax(treeNode *node) {
    if (node == NULL) {
        return NULL;
    }
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}


treeNode* Insert(treeNode *node, int data) {
    if (node == NULL) {
        treeNode *temp = (treeNode *)malloc(sizeof(treeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data) {
        node->left = Insert(node->left, data);
    } else if (data > node->data) {
        node->right = Insert(node->right, data);
    }
    return node;
}


treeNode* Delete(treeNode *node, int data) {
    if (node == NULL) {
        printf("Element not found\n");
        return NULL;
    }
    if (data < node->data) {
        node->left = Delete(node->left, data);
    } else if (data > node->data) {
        node->right = Delete(node->right, data);
    } else {
        
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        } else if (node->left == NULL) {
            treeNode *temp = node->right;
            free(node);
            return temp;
        } else if (node->right == NULL) {
            treeNode *temp = node->left;
            free(node);
            return temp;
        } else {
            
            treeNode *temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
    }
    return node;
}


treeNode* Find(treeNode *node, int data) {
    if (node == NULL) {
        return NULL;
    }
    if (data < node->data) {
        return Find(node->left, data);
    } else if (data > node->data) {
        return Find(node->right, data);
    } else {
        return node;
    }
}


int main() {
    treeNode *root = NULL;
    treeNode *temp;
    int choice, val;

    while (1) {
        printf("\nTree Menu");
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Search an Element");
        printf("\n4. Find Minimum Element");
        printf("\n5. Find Maximum Element");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &val);
                root = Insert(root, val);
                printf("Insertion Successful\n");
                break;
            case 2:
                printf("\nEnter value to delete: ");
                scanf("%d", &val);
                root = Delete(root, val);
                break;
            case 3:
                printf("\nEnter value to search: ");
                scanf("%d", &val);
                temp = Find(root, val);
                if (temp != NULL) {
                    printf("Element %d Found\n", val);
                } else {
                    printf("Element %d Not Found\n", val);
                }
                break;
            case 4:
                temp = FindMin(root);
                if (temp != NULL) {
                    printf("Minimum Element: %d\n", temp->data);
                } else {
                    printf("Tree is Empty\n");
                }
                break;
            case 5:
                temp = FindMax(root);
                if (temp != NULL) {
                    printf("Maximum Element: %d\n", temp->data);
                } else {
                    printf("Tree is Empty\n");
                }
                break;
            case 6:
                printf("Exiting Program...\n");
                exit(0);
            default:
                printf("Invalid Choice! Please try again.\n");
        }
    }
    return 0;
}
