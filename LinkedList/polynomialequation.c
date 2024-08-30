# include<stdio.h>
# include<stdlib.h>

struct Node{
    int coefficient;
    int pow;
    struct Node *next;
};
struct Node* createNode(int coefficient,int pow){
   struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
   ptr->coefficient=coefficient;
   ptr->pow=pow;

   return ptr;        
}

void insertNodeAtTheEnd(struct Node **head,int coefficient,int pow){
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

void displayLinkedList(struct Node *head){
    struct Node *temp;
    temp=head;
    while(temp!=NULL){
        printf("coefficent : %d pow : %d",temp->coefficient,temp->pow);
        printf("\n");
        temp=temp->next;
    }
}

struct Node * addPolynomialEquation(struct Node *head1,struct Node *head2,struct Node **head3){
    struct Node *ptr=*head3;
    struct Node *p1,*p2;
    p1=head1;
    p2=head2;
    while(p1!=NULL && p2!=NULL){            
    if(p1->pow>p2->pow){
       insertNodeAtTheEnd(head3,p1->coefficient,p1->pow);
       p1=p1->next;
    }
    else if(p1->pow<p2->pow){
       insertNodeAtTheEnd(head3,p2->coefficient,p2->pow);
       p2=p2->next;
    }
    else if(p1->pow==p2->pow){
        int sum=p1->coefficient+p2->coefficient;
        insertNodeAtTheEnd(head3,sum,p1->pow);
        p1=p1->next;
        p2=p2->next;
    }
  }
    while(p1!=NULL){
       insertNodeAtTheEnd(head3,p1->coefficient,p1->pow);
       p1=p1->next;
    }
    while(p2!=NULL){
    insertNodeAtTheEnd(head3,p2->coefficient,p2->pow);   
       p2=p2->next;
    }
  return *head3;
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

int main(){
    int n1,n2;
    printf("Enter the number of terms is 1st and second polynomial equation : ");
    scanf("%d %d",&n1,&n2);
    int *coefficient1=(int*)malloc(n1*sizeof(int));
    int *coefficient2=(int*)malloc(n2*sizeof(int));    
    int *pow1=(int*)malloc(n1*sizeof(int));
    int *pow2=(int*)malloc(n2*sizeof(int));

    printf("Enter the coefficient for 1st polynomial equation : \n");
    for(int i=0;i<n1;i++){
        scanf("%d",&coefficient1[i]);
    }
    printf("Enter the power for 1st polynomial equation : \n");
    for(int i=0;i<n1;i++){
        scanf("%d",&pow1[i]);
    }
    sortArray(coefficient1,pow1,n1);
    
    
    printf("\n");
    printf("Enter the coefficient for 2nd polynomial equation : \n");
    for(int i=0;i<n2;i++){
        scanf("%d",&coefficient2[i]);
    }         
    printf("Enter the power for 2nd polynomial equation : \n");
    for(int i=0;i<n2;i++){
        scanf("%d",&pow2[i]);
    }

    sortArray(coefficient2,pow2,n2);
    struct Node *head1=NULL,*head2=NULL;
    for(int i=0;i<n1;i++){
      insertNodeAtTheEnd(&head1,coefficient1[i],pow1[i]);
    }
    for(int i=0;i<n2;i++){
      insertNodeAtTheEnd(&head2,coefficient2[i],pow2[i]);
    }

    
    printf("The linked Node 1 is : \n");
    displayLinkedList(head1);
    printf("\n");

    printf("The linked Node 2 is : \n");
    displayLinkedList(head2); 
    printf("\n");
     
   struct Node *head3=NULL;
   struct Node *ans=addPolynomialEquation(head1,head2,&head3);           

    printf("The linked Node ans is : \n");
    displayLinkedList(head3); 
    printf("\n"); 
    
    return 0;
}
