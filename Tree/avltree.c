#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};
int height(struct Node *node){
    if(node==NULL){
        return -1;
    }
    return node->height;
}

// Function to create a new node
struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height=0;
    return node;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
struct Node * leftLeftRotation(struct Node *node){
    printf("LL Rotation on %d is Applied. \n",node->key);
    struct Node *n1=(struct Node*)malloc(sizeof(struct Node));
    n1=node->left;
    node->left=n1->right;
    n1->right=node;
    node->height=1+max(height(node->left),height(node->right));
    n1->height=1+max(height(n1->left),height(n1->right));
    
    return n1;
}
struct Node * rightRightRotation(struct Node *node){
    printf("RR Rotation on %d is Applied. \n",node->key);
    struct Node *n1=(struct Node*)malloc(sizeof(struct Node));
    n1=node->right;
    node->right=n1->left;
    n1->left=node; 
    node->height=1+max(height(node->left),height(node->right));
    n1->height=1+max(height(n1->left),height(n1->right));

    return n1;
}
struct Node * leftRightRotation(struct Node *node){
    int n=node->key;
    node->left=rightRightRotation(node->left);
    node=leftLeftRotation(node);
    printf("LR Rotation on %d is completed. \n",n);

    return node;
}

struct Node * rightLeftRotation(struct Node * node){
    int n=node->key;
    node->right=leftLeftRotation(node->right);
    node=rightRightRotation(node);
    printf("RL Rotation on %d is completed. \n",n);

    return node;
}


int Balance(struct Node *node){
    if(node==NULL){
        return -1;
    }
    return height(node->left)-height(node->right);
}

// Insert a node in BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
       return node;

    node->height=1+max(height(node->left),height(node->right));

    int balance=Balance(node);
    printf("Balance factor of %d is %d . \n",node->key,balance);

    if(balance>1 && key<node->left->key){
        node=leftLeftRotation(node);
    }
    else if(balance>1 && key>node->left->key){
        node=leftRightRotation(node);
    }
    else if (balance<-1 && key>node->right->key){
        node=rightRightRotation(node);
    }
    else if(balance<-1 && key<node->right->key){
        node=rightLeftRotation(node);
    }

    return node;
}

// Find the minimum value node
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: find the inorder successor
        struct Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    root->height=1+max(height(root->left),height(root->right));

    int balance=Balance(root);
    printf("Balance factor of %d is %d . \n",root->key,balance);

    if(balance>1 && key<root->left->key){
        root=leftLeftRotation(root);
    }
    else if(balance>1 && key>root->left->key){
        root=leftRightRotation(root);
    }
    else if (balance<-1 && key>root->right->key){
        root=rightRightRotation(root);
    }
    else if(balance<-1 && key<root->right->key){
        root=rightLeftRotation(root);
    }

    return root;
}

// In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Pre-order traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Post-order traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;
    
    int ch;
    printf("1)Insert Number \n2)delete Node \n3)Traverse Tree\n4)leave \n");
    do{
        printf("Enter the choice : ");
        scanf("%d",&ch);
        if(ch==1){
            int n;
            printf("Enter the value u want to insert : ");
            scanf("%d",&n);
            root=insert(root,n);
        }
        else if(ch==2){
            int n;
            printf("Enter the value u want to delete : ");
            scanf("%d",&n);
            root=deleteNode(root,n);
        }
        else if(ch==3){
            printf("The inorder traversal is  : \n");
            inorder(root);
            printf("\n");
            printf("The postorder traversal is  : \n");
            postorder(root);
            printf("\n");
            printf("The preorder traversal is  : \n");
            preorder(root);
           
            printf("\n");

        }
    }while(ch!=4);

    return 0;
}
