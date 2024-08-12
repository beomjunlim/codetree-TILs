#include <iostream>
using namespace std;

int R[100001];

int main() {
    string str;
    cin>>str;

    int n = str.length();

    R[n-1] = 0;
    for(int i=n-2; i>=0; i--){
        if(str[i]==')'&&str[i+1]==')')
            R[i] = R[i+1] + 1;
        else
            R[i] = R[i+1];
        
    }
    

    int ans = 0;
    for(int i=1; i<n-2; i++){
        if(str[i-1]=='('&&str[i]=='('){
            ans += R[i+1];
        }
    }

    cout<<ans;
    return 0;
}