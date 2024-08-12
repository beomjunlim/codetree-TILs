#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];
int last[1000001];
int R[200001];

int main() {
    int n,k;
    cin>>n>>k;


    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<=1000000; i++){
        last[i] = -1;
    }

    for(int i=n; i>=1; i--){
        R[i] = last[arr[i]];
        last[arr[i]] = i;
    }

    int ans = -1;
    for(int i=1; i<=n; i++){
        if(R[i]!=-1&&R[i] - i<=k){
            ans = max(ans, arr[i]);
        }
    }

    cout<<ans;
    return 0;
}