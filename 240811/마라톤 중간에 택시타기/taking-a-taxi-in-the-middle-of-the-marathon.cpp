#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int X[100001];
int Y[100001];

int L[100001];
int R[100001];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    L[0] = 0;
    R[n-1] = 0;

    for(int i=1; i<n; i++){
        L[i] = L[i-1] + abs(X[i] - X[i-1]) + abs(Y[i] - Y[i-1]);
    }

    for(int i=n-2; i>=0; i--){
        R[i] = R[i+1] + abs(X[i] - X[i+1]) + abs(Y[i] - Y[i+1]);
    }

    int ans = 1e9;

    for(int i=1; i<n-1; i++){
        int num = L[i-1] + R[i+1] + abs(X[i-1] - X[i+1]) + abs(Y[i-1] - Y[i+1]);
        ans = min(ans, num);
    }

    cout<<ans;
    return 0;
}