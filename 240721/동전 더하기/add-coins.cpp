#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int arr[11];

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    sort(arr, arr+n);

    int num = k;
    int cnt = 0;
    int idx = n-1;

    while(num>0){
        if(num>arr[idx]){
            cnt += num/arr[idx];
            num = num%arr[idx];
        }
        idx--;
    }

    cout<<cnt;
    return 0;
}