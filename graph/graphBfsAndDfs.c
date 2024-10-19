# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

struct Node{
    int data;
    int start,end;
    struct Node *next;
};
struct Stack {
    int top;
    int size;
    int *array;
};

struct Stack* createStack(int size) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int *)malloc(size * sizeof(int));
    return stack;
}
bool isStackFull(struct Stack *stack) {
    return stack->top == stack->size - 1;
}

bool isStackEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int item) {
    if (isStackFull(stack)) {
        printf("Stack is full.\n");
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->array[stack->top--];
}
struct Queue{
    int size;
    int front;
    int rear;
    int *queue;
};

bool isFull(struct Queue *q){
    if(q->rear==q->size-1){
        return true;
    }
    return false;
}
bool isEmpty(struct Queue *q){
    if(q->front>q->rear){
        return true;
    }
    return false;
}
void enqueue(struct Queue *q,int val){
    if(isFull(q)){
        printf("Queue is Full. \n");
    }
    else{
        if(q->rear==-1){
        q->rear++;
        q->queue[q->rear]=val;
        printf("Enqueued : %d \n",val);
        }
        else if(q->rear>=0){
            q->rear++;
            q->queue[q->rear]=val;
            printf("Enqueued : %d \n",val);
        }
    }

}
int dequeue(struct Queue *q){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue is Empty. \n");
    }
    else{
        a=q->queue[q->front];
        printf("Dequed : %d \n" ,a);
        q->front++;
    }
    return a;
}
struct Node * createNode(int n){
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=n;
    ptr->next=NULL;
    
    return ptr;
}
void dfsTraversal(struct Node *arr[], int start, int n) {
    int *visited = (int *)malloc(n * sizeof(int)); // Array to track visited nodes
    int *inTime = (int *)malloc(n * sizeof(int)); // Array to track in-time of each node
    int *outTime = (int *)malloc(n * sizeof(int)); // Array to track out-time of each node
    int time = 0; // Global time variable

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        inTime[i] = -1;
        outTime[i] = -1;
    }

    struct Stack *stack = createStack(n); // Create a stack for iterative DFS
    push(stack, start); // Push the starting node onto the stack

    printf("DFS Traversal is: ");

    while (!isStackEmpty(stack)) {
        int current = stack->array[stack->top]; // Peek the top element of the stack

        // If the current node hasn't been visited, mark it as visited and set in-time
        if (!visited[current]) {
            visited[current] = 1;
            time++;
            inTime[current] = time; // Set in-time for the current node
            printf("%d ", current); // Print the current node as part of the DFS traversal
        }

        // Find the next unvisited neighbor
        struct Node *temp = arr[current];
        bool hasUnvisitedNeighbor = false;
        while (temp != NULL) {
            if (!visited[temp->data]) {
                push(stack, temp->data); // Push the unvisited neighbor onto the stack
                hasUnvisitedNeighbor = true;
                break; // Exit the loop to process this new neighbor
            }
            temp = temp->next;
        }

        // If no unvisited neighbor was found, set out-time and pop the node from the stack
        if (!hasUnvisitedNeighbor) {
            time++;
            outTime[current] = time; // Set out-time for the current node
            pop(stack); // Pop the node from the stack
        }
    }

    printf("\n");
    printf("In Times and Out Times:\n");
    for (int i = 0; i < n; i++) {
        printf("Node %d: In Time = %d, Out Time = %d\n", i, inTime[i], outTime[i]);
    }

    free(visited);
    free(inTime);
    free(outTime);
    free(stack->array);
    free(stack);
}


void bfsTraversal(struct Node *arr[],struct Queue *q,int start,int n){
    int *visited=(int *)malloc(n*sizeof(int));
    int *traversal=(int *)malloc(n*sizeof(int));
    int index=0;
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
   visited[start]=1;
   enqueue(q,start);
   while(!isEmpty(q)){
     int current=dequeue(q);
     traversal[index]=current;
     index++;
     struct Node *temp=arr[current];
     while(temp!=NULL){
        if(visited[temp->data]==0){
            visited[temp->data]=1;
            enqueue(q,temp->data);
        }
        temp=temp->next;
     }
   }
   printf("\n");
   printf("BFS Traversal is : ");
   for(int i=0;i<n;i++){
    printf("%d ",traversal[i]);
   }

   free(visited);
}
void addEdges(struct Node *arr[],int n1,int n2){
   struct Node *newNode1 = createNode(n1);
   struct Node *newNode2 = createNode(n2);


    if (arr[n1] == NULL || arr[n1]->data > n2) {
        newNode2->next = arr[n1];
        arr[n1] = newNode2;
    } else {
        struct Node *temp = arr[n1];
        while (temp->next != NULL && temp->next->data < n2) {
            temp = temp->next;
        }
        newNode2->next = temp->next;
        temp->next = newNode2;
    }


    if (arr[n2] == NULL || arr[n2]->data > n1) {
        newNode1->next = arr[n2];
        arr[n2] = newNode1;
    } else {
        struct Node *temp = arr[n2];
        while (temp->next != NULL && temp->next->data < n1) {
            temp = temp->next;
        }
        newNode1->next = temp->next;
        temp->next = newNode1;
    }
}
void displayGraph(struct Node *arr[],int nodes){
    for(int i=0;i<nodes;i++){
        struct Node *ptr=arr[i];
        struct Node *temp=ptr;
        printf("%d : ",i);
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

}
int main(){
    int nodes;
    int edges;
    printf("Enter the number of Nodes : ");
    scanf("%d",&nodes);
    printf("Enter The number of edges : ");
    scanf("%d",&edges);
    struct Node *arr[nodes];
    for(int i=0;i<nodes;i++){
      arr[i]=NULL;
    }
    printf("Enter the vertices between which edges are present : \n");
    for(int i=0;i<edges;i++){
        int n1,n2;
        printf("Enter the edge number %d : ",i+1);
        scanf("%d %d",&n1,&n2);
        if(n1<0 || n1>=nodes || n2<0 || n2>=nodes){
            printf("Invalid input please enter correct input . \n");
            i--;
            continue;
        }
        addEdges(arr,n1,n2);
        printf("\n");
    }
    printf("The graph is : \n");
    displayGraph(arr,nodes);
    struct Queue *q;
    q->size=nodes;
    q->front=0;
    q->rear=-1;
    q->queue=(int *)malloc(nodes*sizeof(int));
    int start1;
    printf("Enter the starting Point for bfs traversal : ");
    scanf("%d",&start1);
    bfsTraversal(arr,q,start1,nodes);
    printf("\n");
    int start2;
    printf("Enter the starting Point for dfs traversal : ");
    scanf("%d",&start2);
    dfsTraversal(arr,start2,nodes);

    return 0;
}
