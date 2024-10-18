# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>
void qudraticProbing(int *table,int *keys,int t,int k){
    int ans;
    for(int i=0;i<k;i++){
        ans=keys[i]%t;
        if(table[ans]==-1){
            table[ans]=keys[i];
            printf("At index %d %d keys is inserted. \n",ans,keys[i]);
        }
        else{
            printf("Collision on table index %d .\n",ans);
            int j=1;
            int index=ans;
            while(table[index]!=-1){
                printf("%dth probing .\n",j);
                index=(ans+j*j)%t;
                printf("index =(h(k)+j*j)mod(tablesize) \n");
                printf("index=(%d + %d*%d)mod%d=%d \n",ans,j,j,t,index);
                j++;
            }
            table[index]=keys[i];
            printf("At index %d %d keys is inserted. \n",index,keys[i]);
        }
    }
    printf("\n");
    printf("The Hash Table for Quadratic Probing is : \n");
    printf("Index : Element \n");
    for(int i=0;i<t;i++){
        printf("%d : %d \n",i,table[i]);
    }
}
void linearProbing(int *table,int *keys,int t,int k){
    int ans;
    for(int i=0;i<k;i++){
        ans=keys[i]%t;

        if(table[ans]==-1){
            table[ans]=keys[i];
            printf("At index %d %d keys is inserted. \n",ans,keys[i]);
        }
        else{
            printf("Collision on table index %d .\n",ans);
            int j=1;
            int index=ans;
            while(table[index]!=-1){
                printf("%dth probing .\n",j);
                index=(ans+j)%t;
                printf("index =(h(k)+j)mod(tablesize) \n");
                printf("index=(%d + %d)mod%d=%d \n",ans,j,t,index);
                j++;
            }
            table[index]=keys[i];
            printf("At index %d %d keys is inserted. \n",index,keys[i]);
        }
    }
    printf("\n");
    printf("The Hash Table for linear Probing is : \n");
    printf("Index : Element \n");
    for(int i=0;i<t;i++){
        printf("%d : %d \n",i,table[i]);
    }
}
int main(){
    int tableSize;
    int noOfKeys;
    printf("Enter size of table : ");
    scanf("%d",&tableSize);
    printf("Enter the number of keys : ");
    scanf("%d",&noOfKeys);
    int *table1=(int *)malloc(tableSize*sizeof(int));
    int *table2=(int *)malloc(tableSize*sizeof(int));
    int *keys=(int *)malloc(noOfKeys*sizeof(int));
    printf("Enter the keys in the array keys : \n");
    for(int i=0;i<noOfKeys;i++){
        scanf("%d",&keys[i]);
    }
    for(int i=0;i<tableSize;i++){
        table1[i]=-1;
        table2[i]=-1;
    }
    printf("\nThe operation on linear probing are as follow : \n");
    linearProbing(table1,keys,tableSize,noOfKeys);
    printf("\n");
    qudraticProbing(table2,keys,tableSize,noOfKeys);

    return 0;
}
