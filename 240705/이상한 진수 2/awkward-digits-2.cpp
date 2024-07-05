#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string str;
    cin>>str;

    bool sw = false;
    int ans[11];
    int n = str.length();

    for(int i=0; i<n; i++){
        if(str[i]=='0'&&!sw){
            sw = true;
            ans[i] = 1;
        }
        else{
            ans[i] = str[i] - '0';
        }
    }

    if(!sw)
        ans[n-1] = 0;
    
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += pow(2, n-1-i)*ans[i];
    }

    cout<<sum;

    return 0;
}