# include<stdio.h>
# include<stdlib.h>

struct Node{
    int data;
    struct Node *right;
    struct Node *left;
}; 
struct Node * createNode(int data){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->right=NULL;
    ptr->left=NULL;
    return ptr;
}
void insertNodeAtTheEnd(struct Node **head,int data){
    struct Node *newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
    }
    struct Node *p;
    p=*head;
    while(p->right!=NULL){
        p=p->right;
    }
    p->right=newNode;
    newNode->left=p;
    newNode->right=NULL;
}

void createDoublyLinkedList(struct Node **head,int arr[],int n){
    for(int i=0;i<n;i++){
        insertNodeAtTheEnd(head,arr[i]);
    }
}
void displayLinkedList(struct Node *head){
    struct Node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->right;
    }
}
void displayInFromEnd(struct Node *head,int n){
    struct Node *temp=head;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    for(int i=0;i<n;i++){
        printf("%d ",temp->data);
        temp=temp->left;
    }
}
int main(){
    printf("Enter the no of element you want to insert in linked list : ");
    int n;
    scanf("%d",&n);
    int *arr=(int *)malloc(sizeof(int)*n);
    printf("Enter the array element : \n");   
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    struct Node *head=NULL;
    createDoublyLinkedList(&head,arr,n);
    printf("The doubly linked list is : \n");
    displayLinkedList(head);
    printf("\n");
    displayInFromEnd(head,n);
    


    return 0;
}
