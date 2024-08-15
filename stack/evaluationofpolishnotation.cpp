# include<bits/stdc++.h>
using namespace std;

// This is about evaluation of polish notation 
int evaluationOfPostfixNotation(string str){
    stack<int> st;
    int n=str.length();
    for(int i=0;i<n;i++){
        char ch=str[i];
      if(isdigit(ch)){
        st.push(ch-'0');
      }
      else{
        int right=st.top();
        st.pop();
        if(ch=='~') st.push(~right) ;
        else {
            int left=st.top();
            st.pop();
            switch(ch){
                case '+' : 
                st.push(left+right);
                break;
                case '-' : 
                st.push(left-right);
                break;
                case '*' :
                st.push(right*left);
                break;
                case '/' :
                st.push(left/right);
                break;
                case '^':
                st.push(left^right);
                break;
            }
        }
        
      }
    }
    int ans=st.top();
    st.pop();

    return ans;
}
int evaluationOfPrefixNotation(string str){
    stack<int> st;
    int n=str.length();
    for(int i=n-1;i>=0;i--){
        char ch=str[i];
      if(isdigit(ch)){
        st.push(ch-'0');
      }    
      else{
        int left=st.top();
        st.pop();
        if(ch=='~') st.push(~left) ;
        else {
            int right=st.top();
            st.pop();
            switch(ch){
                case '+' : 
                st.push(left+right);
                break;
                case '-' : 
                st.push(left-right);
                break;
                case '*' :
                st.push(right*left);
                break;
                case '/' :
                st.push(left/right);
                break;
                case '^':
                st.push(left^right);
                break;
            }
        }
        
      }
    }
    int ans=st.top();
    st.pop();

    return ans;
}
int main(){
    string str1;
    cout<<"Enter the expression for evaluation of postfix notation : \n";
    cin>>str1;
    int ans1=evaluationOfPostfixNotation(str1);
    cout<<"The evaluation of postfix notation is : "<<ans1<<"\n \n";

    string str2;
    cout<<"Enter the expression for evaluation of postfix notation : \n";
    cin>>str2;
    int ans2=evaluationOfPrefixNotation(str2);
    cout<<"The evaluation of postfix notation is : "<<ans2;


    return 0;
}