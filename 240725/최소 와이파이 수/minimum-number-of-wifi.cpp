#include <iostream>
using namespace std;

int n,m;
int arr[101];

int function(int idx){
    int left = -1;
    for(int i = idx; i<=idx+2*m; i++){
        if(i>=n)
            break;
        if(arr[i]==1){
            left = i;
            break;
        }
    }

    if(left==-1)
        return -1;
    return left;
}

int main() {

    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>arr[i];


    int idx = 0;
    int ans = 0;
    while(idx<n){
        int num = function(idx);
        
        if(num==-1)
            idx += (2*m+1);
        else{
            ans++;
            idx = num + 2*m + 1;
        }
    }

    cout<<ans;
    return 0;
}