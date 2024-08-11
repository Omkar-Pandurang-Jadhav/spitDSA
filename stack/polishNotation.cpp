# include<bits/stdc++.h>
using namespace std;

// This program is about poslish notation to convert infix to postfix and prefix

int precedence(char ch){
    if(ch=='^') return 3;
    else if(ch=='*' || ch=='/') return 2;
    else if(ch=='+' || ch=='-') return 1;
    else if(ch=='(' || ch==')') return 0;     
    return -1;
}

void reverseExpression(string &str,int start,int end){
    for(int i=0;i<=end;i++){
        if(str[i]=='(') str[i]=')';
        else if (str[i]==')') str[i]='(';
    }
    while(start<end){
        char temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}

void reverseArray(vector<char> &pf,int start,int end){
    if(start<end){
       char temp=pf[start];
       pf[start]=pf[end];
       pf[end]=temp;
       reverseArray(pf,start+1,end-1);
    }
}

vector<char> postFix(string str){
    int n=str.length();
    vector<char> pf;
    stack <char> st;
    for(int i=0;i<n;i++){
        char ch=str[i];
        if(ch=='(') st.push(ch);
        else if(ch==')'){
            while(st.top()!='('){
                pf.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if(precedence(ch)==-1) pf.push_back(ch);
        else if(!st.empty()){
            if(precedence(ch)<=precedence(st.top())){
            pf.push_back(st.top());
            st.pop();
            st.push(ch);
            }
            else if(precedence(ch)>precedence(st.top())){
                st.push(ch);
            }
        }
        else if(st.empty()){
            st.push(ch);
        }
    }
    while(!st.empty()){
        pf.push_back(st.top());
        st.pop();
    }

    return pf;
}

vector<char> preFix(string str){
    reverseExpression(str,0,str.length()-1);
    vector<char> pf=postFix(str);
    reverseArray(pf,0,pf.size()-1);

    return pf;
}
int main(){
    string str;
    cout<<"Enter the erxpression you want to convert it into postfix or prefix : \n";
    cin>>str;
    vector<char> postfix=postFix(str);
    cout<<"The postFix expression is : \n";                     
    for(int i=0;i<postfix.size();i++){
        cout<<postfix[i]<<" ";
    }
    cout<<"\n";
    vector<char> prefix=preFix(str);
    cout<<"The preFix expression is : \n";
    for(int i=0;i<prefix.size();i++){
        cout<<prefix[i]<<" ";
    }


    return 0;
}
