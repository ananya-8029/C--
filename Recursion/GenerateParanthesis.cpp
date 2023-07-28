#include <bits/stdc++.h>
using namespace std;

//Function generate balanced paranthesis
void generateParanthesis(int i,int j,string ans){

    //base condition
    if(i == 0 && j == 0){      
        cout<<ans<<endl;
        return;
    }

    if(i!=0){
        string op1=ans;
        op1.push_back('(');
        generateParanthesis(i-1,j,op1);
    }

    if(i<j){
        string op2=ans;
        op2.push_back(')');
        generateParanthesis(i,j-1,op2);
    }
}

//Driver Program
int main(){
    int n;
    cout<<"Enter number of pair of paranthesis:"<<endl;
    cin>>n;
    string ans;
    int open=n;
    int close=n;

    generateParanthesis(open,close,ans);
    return 0;
}