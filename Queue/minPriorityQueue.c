# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
struct priorityQueue{
    int size;
    int front;
    int rear;
    int *arr;
};

void insertionSort(struct priorityQueue *pq){
    for(int i=pq->front+1;i<=pq->rear;i++){
        int j=i;
        while(j>pq->front && pq->arr[j-1]>pq->arr[j]){
            int temp=pq->arr[j-1];
            pq->arr[j-1]=pq->arr[j];
            pq->arr[j]=temp;
            j--;
        }
    }
}

bool isFull(struct priorityQueue *pq){
    if(pq->rear==pq->size-1){
        return true;
    }
    return false;
}

bool isEmpty(struct priorityQueue *pq){
    if(pq->front>pq->rear){
        return true;
    }
    return false;
}
void enqueue(struct priorityQueue *pq,int val){
    if(isFull(pq)){
        printf("Queue is Full. \n");
    }
    else{
        if(pq->rear==-1){
        pq->rear++;
        pq->arr[pq->rear]=val;
        }
        else if(pq->rear>=0){
            pq->rear++;
            pq->arr[pq->rear]=val;
            insertionSort(pq);
        }
    }

}

int dequeue(struct priorityQueue *pq){
    int a=-1;
    if(isEmpty(pq)){
        printf("Queue is Empty. \n");
    }
    else{
        a=pq->arr[pq->front];
        printf("The element %d is removed from the queue . \n",a);
        pq->front++;
    }
    return a;
}
void printQueue(struct priorityQueue *pq){
    for(int i=pq->front;i<=pq->rear;i++){
       printf("%d",pq->arr[i]);
       printf(" ");
    }
    printf("\n");
}
int main(){
    struct priorityQueue pq;
    printf("Enter the size of an Queue : \n");
    scanf("%d",&pq.size);
    pq.arr=(int*)malloc(pq.size*sizeof(int));
    pq.front=0;
    pq.rear=-1;
    printf("1)Insertion. \n2)Deletion \n 3)PrintQueue \n");
    int n;
     do{
        printf("Enter the number based on your choice : ");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the value you want to insert in Queue : ");
            int val;
            scanf("%d",&val);
            enqueue(&pq,val);
        }
        else if(n==2){
            dequeue(&pq);
        }
        else if(n==3){
            printQueue(&pq);
        }
    } while(n>=1 && n<=3);

    free(arr);

    return 0;
}
