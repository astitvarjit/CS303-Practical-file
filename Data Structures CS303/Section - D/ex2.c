#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    int data;
    struct treeNode *left, *right;
} treeNode;

// Function to create a new node
treeNode* createNode(int data) {
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
treeNode* insert(treeNode *root, int data) {
    if (root == NULL) 
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Function to find the minimum value node in a BST
treeNode* findMin(treeNode *root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Function to find the maximum value node in a BST
treeNode* findMax(treeNode *root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Function to delete a node in the BST
treeNode* deleteNode(treeNode *root, int data) {
    if (root == NULL) {
        printf("Element %d not found.\n", data);
        return root;
    }
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with one child or no child
        if (root->left == NULL) {
            treeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            treeNode *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        treeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search a node in the BST
treeNode* search(treeNode *root, int data) {
    if (root == NULL || root->data == data)
        return root;
    if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}

// Traversal functions
void inOrder(treeNode *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void preOrder(treeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(treeNode *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Main function with menu
int main() {
    treeNode *root = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n6. Post-order Traversal\n");
        printf("7. Find Minimum\n8. Find Maximum\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted %d into the BST.\n", value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("Element %d found in the BST.\n", value);
                else
                    printf("Element %d not found in the BST.\n", value);
                break;
            case 4:
                printf("In-order Traversal: ");
                inOrder(root);
                printf("\n");
                break;
            case 5:
                printf("Pre-order Traversal: ");
                preOrder(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order Traversal: ");
                postOrder(root);
                printf("\n");
                break;
            case 7:
                if (root) 
                    printf("Minimum element: %d\n", findMin(root)->data);
                else
                    printf("The tree is empty.\n");
                break;
            case 8:
                if (root) 
                    printf("Maximum element: %d\n", findMax(root)->data);
                else
                    printf("The tree is empty.\n");
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
