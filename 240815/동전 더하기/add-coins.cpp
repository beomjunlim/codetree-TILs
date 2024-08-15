#include <iostream>
#include <algorithm>
using namespace std;

int arr[11];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    int cnt = 0;
    int num = k;
    int idx = n-1;
    while(num>0){
        if(arr[idx]<num){
            cnt += num/arr[idx];
            num = num%arr[idx];
        }
        idx--;
    }

    cout<<cnt;
    return 0;
}