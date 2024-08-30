# include<stdio.h>
# include<stdlib.h>

struct Node{
    int coefficient;
    int pow;
    struct Node *next;
};
struct Node * createNode(int coefficient,int pow){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node *));
    ptr->coefficient=coefficient;
    ptr->pow=pow;

    return ptr;
}

void insertnodeAtTheEnd(struct Node **head,int coefficient,int pow){
    struct Node *newNode=createNode(coefficient,pow);
    if(*head==NULL){
        *head=newNode;
        newNode->next=NULL;
        return;
    }
    struct Node *p;
    p=*head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newNode;
    newNode->next=NULL;
}
void arrayInput(int arr[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void createLinkedList(struct Node **head,int n,int coefficient[],int pow[]){
    for(int i=0;i<n;i++){
        insertnodeAtTheEnd(head,coefficient[i],pow[i]);
    }
}

void displayLinkedList(struct Node *head){
    struct Node *p;
    p=head;
    while(p!=NULL){
      printf("%d,%d-> ",p->coefficient,p->pow);
      p=p->next;
    }
    printf("NULL");
}

void sortArray(int coefficient[],int pow[],int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(pow[i]<pow[j]){
                int temp1=pow[i];
                pow[i]=pow[j];
                pow[j]=temp1;

                int temp2=coefficient[i];
                coefficient[i]=coefficient[j];
                coefficient[j]=temp2;
            }
        }
    }
}

void addPolynomialEquation(struct Node *head1,struct Node *head2,struct Node **head3){
  struct Node *p1=head1;
  struct Node *p2=head2;
   while(p1!=NULL && p2!=NULL){
    if(p1->pow>p2->pow){
        insertnodeAtTheEnd(head3,p1->coefficient,p1->pow);
        p1=p1->next;
    }
    else if(p1->pow<p2->pow){
        insertnodeAtTheEnd(head3,p2->coefficient,p2->pow);
        p2=p2->next;
    }
    else if(p1->pow==p2->pow){
        int sum=p1->coefficient+p2->coefficient;
        insertnodeAtTheEnd(head3,sum,p1->pow);
        p1=p1->next;
        p2=p2->next;
    }
   }
   while(p1!=NULL){
    insertnodeAtTheEnd(head3,p1->coefficient,p1->pow);
    p1=p1->next;
   }
   while(p2!=NULL){
    insertnodeAtTheEnd(head3,p2->coefficient,p2->pow);
    p2=p2->next;
   }
}
int main(){
    int n1,n2;
    printf("Enter the number of term in 1st and 2nd polynomial equation : ");
    scanf("%d %d",&n1,&n2);
    int *coefficient1=(int *)malloc(n1*sizeof(int));
    int *coefficient2=(int *)malloc(n2*sizeof(int));
    int *pow1=(int *)malloc(n1*sizeof(int));
    int *pow2=(int *)malloc(n2*sizeof(int));

    printf("Enter the coefficient for equation 1 : \n");
    arrayInput(coefficient1,n1);
    printf("Enter the power for equation 1 : \n");
    arrayInput(pow1,n1);
    printf("Enter the coefficient for equation 2 : \n");
    arrayInput(coefficient2,n2);
    printf("Enter the power for equation 2 : \n");
    arrayInput(pow2,n2);
    sortArray(coefficient1,pow1,n1);
    sortArray(coefficient2,pow2,n2);


    struct Node *head1=NULL;
    struct Node *head2=NULL;
    createLinkedList(&head1,n1,coefficient1,pow1);
    createLinkedList(&head2,n2,coefficient2,pow2);
    printf("The linked list 1 is : \n");
    displayLinkedList(head1);
    printf("\n");
    printf("The linked list 2 is : \n");
    displayLinkedList(head2);

    printf("\n");

    struct Node *head3=NULL;
    addPolynomialEquation(head1,head2,&head3);
    printf("The addition of polynomial equation is : \n");
    displayLinkedList(head3);
    printf("\n");

    free(head1);
    free(head2);
    free(head3);
    free(coefficient1);
    free(coefficient2);
    free(pow1);
    free(pow2);

    return 0;
}