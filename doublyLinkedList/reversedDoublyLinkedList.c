# include<stdio.h>
# include<stdlib.h>
struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};
void insertNodeAtTheEnd(struct Node **head,int data){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    if(*head==NULL){
        *head=newNode;
    }
    else {
        struct Node *p;
        p=*head;
        while(p->right!=NULL){
            p=p->right;
        }
        p->right=newNode;
        newNode->left=p;
    }
    
    
}
void displayDoublyLinkedList(struct Node *head){
    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->right;
    }
    printf("\n");
}
struct Node *reverseDoublyLinkedList(struct Node **head){
   struct Node *current=*head;
   struct Node *temp=NULL;
   struct Node *newHead = NULL;

   
   while(current!=NULL){
      temp=current->left;
      current->left=current->right;
      current->right=temp;
      
      newHead=current;
      current=current->left;
   }
    *head=newHead;
   return *head;
}
int main(){
    printf("1)Insert element \n2)Stop \n \n");
    struct Node *head=NULL;
    int n;
    do{
        printf("Enter the number based on your choice : \n");
        scanf("%d",&n);
        if(n==1){
            int data;
            printf("Enter the Data : ");
            scanf("%d",&data);
            insertNodeAtTheEnd(&head,data);
        }
    }while(n!=2);

    printf("The doubly linked list is : \n");
    displayDoublyLinkedList(head);
    head=reverseDoublyLinkedList(&head);
    printf("The reversed doubly linked list is : \n");
    displayDoublyLinkedList(head);

    return 0;
}