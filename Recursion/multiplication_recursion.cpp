#include <iostream>
using namespace std;

int multiplication(int a,int b){
    
    if (b==0)
        return 0;
    int ans = a+multiplication(a,b-1);
    return ans;
}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int x,y;
        cin>>x;
        cin>>y;
        
        int result = multiplication(x,y);
        cout<<result<<endl;
    }
	return 0;
}
