# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

# define MAX_QUEUE 10
struct MultipleQueue {
    int size;
    int front[MAX_QUEUE];
    int rear[MAX_QUEUE];
    int numQueue;
    int capacity;
    int *arr;
};
bool isFull(struct MultipleQueue *mq,int qIndex){
    if(mq->rear[qIndex]==(qIndex+1)*mq->capacity-1){
       return true;
    }
    return false;
}
bool isEmpty(struct MultipleQueue *mq,int qIndex){
    if(mq->front[qIndex]>mq->rear[qIndex]){
        return true;
    }
    return false;
}
void enqueue(struct MultipleQueue *mq,int qIndex,int val){
     if(isFull(mq,qIndex)){
        printf("Queue %d is full. \n",qIndex);
     }
     else{
        mq->rear[qIndex]++;
        mq->arr[mq->rear[qIndex]]=val;
     }
}
int dequeue(struct MultipleQueue *mq,int qIndex){
    int a=-1;
    if(isEmpty(mq,qIndex)){
        printf("Queue %d is empty. \n",qIndex);
    }
    else {
        a=mq->arr[mq->front[qIndex]];
        mq->front[qIndex]++;
        printf("The element %d is dequeued from queue %d \n",a,qIndex);
    }
    return a;
}
void createMultipleQueue(struct MultipleQueue *mq,int size,int numQueue){
     mq->size=size;
     mq->capacity=mq->size/numQueue;
     mq->arr=(int*)malloc(mq->size*sizeof(int));
     for(int i=0;i<numQueue;i++){
        mq->front[i]=i*mq->capacity;
        mq->rear[i]=i*mq->capacity-1;
     }
}
void printQueue(struct MultipleQueue *mq,int qIndex){
    for(int i=mq->front[qIndex];i<=mq->rear[qIndex];i++){
        printf("%d",mq->arr[i]);
        printf(" ");
    }
    printf("\n");
}

int main(){
    struct MultipleQueue mq;
    createMultipleQueue(&mq,10,5);
    dequeue(&mq,0);
    dequeue(&mq,1);

    enqueue(&mq,0,10);
    enqueue(&mq,0,20);

    enqueue(&mq,1,15);
    enqueue(&mq,1,25);

    enqueue(&mq,0,30);
    enqueue(&mq,1,35);

    printf("Queue 0 : \n");
    printQueue(&mq,0);

    printf("Queue 1 : \n");
    printQueue(&mq,1);

    printf("Queue 2 : \n");
    printQueue(&mq,2);

    dequeue(&mq,0);
    dequeue(&mq,1);

    printf("Queue 0 : \n");
    printQueue(&mq,0);

    printf("Queue 1 : \n");
    printQueue(&mq,1);



    return 0;
}
