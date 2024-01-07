#include <iostream>
#include <climits>
using namespace std;

#define MAX 100000
int arr[MAX+1];
int num[MAX+1];

int main() {
    int n,k,b;
    cin>>n>>k>>b;
    
    arr[0] = 0;


    for(int i=0; i<b; i++){
        int x;
        cin>>x;
        num[x] = 1;
    }

    arr[0] = 0;
    for(int i=1; i<=n; i++){
        arr[i] = arr[i-1] + num[i];
    }

    int ans = INT_MAX;
    for(int i=k; i<=n; i++){
        ans = min(ans, arr[i]-arr[i-k]);
    }

    cout<<ans;
    return 0;
}