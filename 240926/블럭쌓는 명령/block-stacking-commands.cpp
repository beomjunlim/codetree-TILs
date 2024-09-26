#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
int arr[1000001];
int ans[1000001];

int main() {
    cin>>n>>k;

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }

    ans[1] = arr[1];
    for(int i=2; i<=n; i++){
        ans[i] = ans[i-1] + arr[i];
    }

    sort(ans, ans+n);

    cout<<ans[n/2];


    return 0;
}