#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

#define MAX 100000

int x[MAX+1];
int y[MAX+1];
int L[MAX+1];
int R[MAX+1];


int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>x[i]>>y[i];
    }

    for(int i=2; i<=n; i++){
        L[i] = L[i-1] + (abs(x[i]-x[i-1])+abs(y[i]-y[i-1]));
        R[n-i+1] = R[n-i+2] + (abs(x[n-i+1]-x[n-i+2]+abs(y[n-i+1]-y[n-i+2])));
    }

    int ans = INT_MAX;
    for(int i=2; i<n; i++){
        ans = min(ans, L[i-1]+R[i+1]+abs(x[i-1]-x[i+1])+abs(y[i-1]-y[i+1]));
    }

    cout<<ans;
    return 0;
}