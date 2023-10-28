#include <bits/stdc++.h>
using namespace std;

//Bit Masking Method
void find_subsequence(string &str){
    int nums=pow(2,str.size());
    int i=0;
    while(i<nums){
        string output;

        //Convert i into its binary equivalent
        int index=0;
        int num = i;
        while(num){
            int binary=num&1;
            if(binary){
                output.push_back(str[index]);
            }
            index++;
            num=num>>1;
        }
        i++;
        cout<<"->"<<output<<endl;
    }
}

int main(){
    string str="abc";
    cout<<"The subsequence of the string : "<<str<<endl;
    find_subsequence(str);
    return 0;
}