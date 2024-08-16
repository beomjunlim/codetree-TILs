#include <iostream>
using namespace std;

int arr[103];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt = 0;

    for(int i=1; i<n; i++){
        if(arr[i-1]==0){
            cnt++;
            arr[i-1] = 1;
            arr[i] = 1 - arr[i];
            arr[i+1] = 1 - arr[i+1];
        }
    }

    if(arr[n-1]==0)
        cnt = -1;
    cout<<cnt;
    return 0;
}