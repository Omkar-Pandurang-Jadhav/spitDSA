# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

# define MAX 100
int st[100];
static int topindex=-1;

void reversArray(char prefix[],int n){

    int start=0;
    int end=n-1;
    while(start<end){
        char temp=prefix[start];
        prefix[start]=prefix[end];
        prefix[end]=temp;
        start++;
        end--;
    }
}
void push(char value){
    if(topindex>=MAX-1){
        printf("Stack overflow");
        return;
    }
    else{
        st[++topindex]=value;
    }
}

void pop(){
    if(topindex<0){
        printf("Stack underflow");
        return;
    }
    else {
        topindex--;
    }
}

int top(){
    if(topindex<0){
        return -1;
    }
    else{
        return st[topindex];
    }
}
bool isempty(){
    if(topindex==-1) return true;
    else return false;
}
void add_edges(int n1,int n2,int **arr){
   arr[n1][n2]=1;
   arr[n2][n1]=1;
}
void display_graph(int v,int **arr){
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int v;
    int e;
    printf("Enter the number of Vertices : ");
    scanf("%d",&v);
    printf("Enter the number of Edges : ");
    scanf("%d",&e);
    int **arr=(int **)malloc(v*sizeof(int *));
    for(int i=0;i<v;i++){
        arr[i]=(int *)malloc(v*sizeof(int));
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    for(int i=0;i<e;i++){
        int n1,n2;
        printf("Enter the edges %d : ",i+1);
        scanf("%d %d",&n1,&n2);
        add_edges(n1,n2,arr);
    }
    printf("The graph is : \n");
    display_graph(v,arr);
    printf("\n");
    printf("Enter the source element : ");
    int s;
    scanf("%d",&s);


    return 0;
}
