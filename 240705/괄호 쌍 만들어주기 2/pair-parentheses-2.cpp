#include <iostream>
using namespace std;

int main() {
    string str;
    cin>>str;

    int n = str.length();
    int ans = 0;
    for(int i=0; i<n-3; i++){
        if(str[i]=='('&&str[i+1]=='('){
            for(int j=i+2; j<n-1; j++){
                if(str[j]==')'&&str[j+1]==')')
                    ans++;
            }
        }
    }

    cout<<ans;
    return 0;
}