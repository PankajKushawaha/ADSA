#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;               
    struct Node* left;       
    struct Node* right;   
} Node;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data;            
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data); 
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data); 
    }
    return root;
}

void Preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);  
    Preorder(root->left);       
    Preorder(root->right);      
}

void Inorder(struct Node* root) {
    if (root == NULL)
        return;

    Inorder(root->left);       
    printf("%d ", root->data);  
    Inorder(root->right);        
}

void Postorder(struct Node* root) {
    if (root == NULL)
        return;

    Postorder(root->left);      
    Postorder(root->right);  
    printf("%d ", root->data);  
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root; // Found or tree is empty
    }

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct Node* r = NULL; 

    printf("Enter the number of elements: ");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        int data;
        scanf("%d", &data);
        r = insert(r, data);
    }

    printf("Preorder: ");
    Preorder(r);
    printf("\n");

    printf("Inorder: ");
    Inorder(r);
    printf("\n");

    printf("Postorder: ");
    Postorder(r);
    printf("\n");

    int key;
    printf("Enter value to search: ");
    scanf("%d", &key);
    struct Node* found = search(r, key);
    if (found != NULL)
        printf("Value %d found in the tree.\n", key);
    else
        printf("Value %d not found in the tree.\n", key);

    return 0;
}