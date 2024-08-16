# include<bits/stdc++.h>
using namespace std;

# define MAX 100
char arr[100];
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
        cout<<"Stack overflow";
        return;
    }
    else{
        arr[++topindex]=value;
    }
}

void pop(){
    if(topindex<0){
        cout<<"Stack underflow";
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
        return arr[topindex];
    }
}
bool isempty(){
    if(topindex==-1) return true;
    else return false;
}
int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;

    return 0;
}
void prefix(string str){
    int k=0;
    char prefix[100];
    int n=str.size();
    for(int i=n-1;i>=0;i--){
        char ch=str[i];
        if(ch==')'){
         push(ch);
        }
        else if(ch=='('){
            while(!isempty() && top()!=')'){
              prefix[k]=arr[topindex];
              k++;
              pop();
            }
            pop();
        }
        else if(precedence(ch)==0){
            prefix[k]=ch;
            k++;
        }
        else if(!isempty()){
            if(precedence(ch)<=precedence(top())){
                prefix[k]=top();
                k++;
                pop();
                push(ch);
            }
            else if(precedence(ch)>precedence(top())){
                push(ch);
            }
        }
        else if(isempty()){
            push(ch);
        }
    }
    while(!isempty()){
            prefix[k]=top();
            pop();
            k++;
        }
      reversArray(prefix,k);
      cout<<"The prefix expression is : \n";
      for(int i=0;i<k;i++){
        cout<<prefix[i]<<" ";
      }
}
int main(){
    string str;
    cout<<"Enter the expression you want to convert it into prefix : \n";
    cin>>str;
    prefix(str);


    return 0;
}