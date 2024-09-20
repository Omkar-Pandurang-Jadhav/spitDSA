#include<stdio.h>
#include<stdlib.h>
# include<string.h>
# include<ctype.h>

struct Node{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node * newNode(int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}

int isOperator(char c){

    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='~');
}

struct Node * constructExpressionTree(char preOrder[]){
    struct Node *stack[100];
    int top=-1;
   // int n=sizeof(preOrder);
    for(int i=strlen(preOrder)-1;i>=0;i--){
       if(!isOperator(preOrder[i])){
        stack[++top]=newNode(preOrder[i]);
        printf("Push %c \n",preOrder[i]);
       }
       else if(isOperator(preOrder[i])){
        struct Node *operator=(struct Node *)malloc(sizeof(struct Node));
        printf("Pop %c \n",stack[top]->data);
        operator->left=stack[top--];
        printf("Pop %c \n",stack[top]->data);
        
        operator->right=stack[top--];
        stack[++top]=operator;
        printf("Push %c \n",preOrder[i]);
       }
    }

    return stack[top];
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c ", root->data);
        inorderTraversal(root->right);
    }
}
int main(){
    char preOrder[100];
    int choice;
    printf("Enter preOrder Expression : ");
    scanf("%s",preOrder);
    struct Node *root=NULL;
    root=constructExpressionTree(preOrder);
    printf("The inorder expression is : \n");
    inorderTraversal(root);
   
    
    


    return 0;
}