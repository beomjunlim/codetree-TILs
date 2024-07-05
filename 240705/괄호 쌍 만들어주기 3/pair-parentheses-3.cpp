#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;
    
    int n = str.length();
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(str[i]=='('){
            for(int j=i+1; j<n; j++){
                if(str[j]==')')
                    ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}