#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int num = n/5;
    int cnt = 0;
    for(int i=num; i>=0; i--){
        int a = i*5;
        if((n-a)%2==0){
            cnt = i+(n-a)/2;
            break;
        }
    }

    if(cnt==0)
        cnt = -1;
    cout<<cnt;
    return 0;
}