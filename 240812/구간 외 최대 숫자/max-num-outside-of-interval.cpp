#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int L[100001];
int R[100001];

int main() {
    int n,q;
    cin>>n>>q;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    L[1] = arr[1];

    for(int i=2; i<=n; i++){
        if(arr[i]>L[i-1])
            L[i] = arr[i];
        else
            L[i] = L[i-1];
    }

    R[n] = arr[n];

    for(int i=n-1; i>0; i--){
        if(arr[i]>R[i+1])
            R[i] = arr[i];
        else
            R[i] = R[i+1];
    }

    for(int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;

        cout<<max(L[a-1], R[b+1])<<'\n';
    }
    return 0;
}