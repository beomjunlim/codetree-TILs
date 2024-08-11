#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int L[100001], R[100001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    L[1] = arr[1];
    for(int i=2; i<=n; i++){
        L[i] = max(L[i-1], arr[i]);
    }

    R[n] = arr[n];

    for(int i=n-1; i>0; i--){
        R[i] = max(R[i+1], arr[i]);
    }

    int ans = 0;
    for(int i=3; i<=n-2; i++){
        ans = max(ans, L[i-2] + arr[i] + R[i+2]);
    }

    cout<<ans;
    return 0;
}