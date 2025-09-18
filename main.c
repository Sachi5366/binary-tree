#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Manually build binary tree using user input (left/right choice)
void insert(struct Node* root) {
    struct Node* temp = root;
    while (1) {
        char dir;
        printf("Insert left or right of %d (l/r)? ", temp->data);
        scanf(" %c", &dir);
        if (dir == 'l') {
            if (temp->left == NULL) {
                int val;
                printf("Enter value: ");
                scanf("%d", &val);
                temp->left = createNode(val);
                break;
            } else {
                temp = temp->left;
            }
        } else if (dir == 'r') {
            if (temp->right == NULL) {
                int val;
                printf("Enter value: ");
                scanf("%d", &val);
                temp->right = createNode(val);
                break;
            } else {
                temp = temp->right;
            }
        }
    }
}

void inorder(struct Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    int rootVal, n;
    printf("Enter root value: ");
    scanf("%d", &rootVal);
    struct Node* root = createNode(rootVal);

    printf("How many nodes to insert? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        insert(root);

    printf("Inorder traversal: ");
    inorder(root);
    return 0;
}
