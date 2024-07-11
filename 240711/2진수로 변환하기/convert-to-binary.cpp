#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int idx = 0;
    int arr[100001];
    if(n>1){
        while(n!=1){
            arr[idx] = n%2;
            n /= 2;
            idx++;
        }
        arr[idx] = n;
    }
    else{
        if(n==0)
            arr[idx] = 0;
        else
            arr[idx] = 1;
    }
    for(int i=idx; i>=0; i--)
        cout<<arr[i];
    return 0;
}