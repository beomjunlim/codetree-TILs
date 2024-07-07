#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
long long ans = 9876543210000;
int X[101];
int Y[101];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long dx = X[i] - X[j];
            long long dy = Y[i] - Y[j];
            long long dist = dx * dx + dy * dy;
            ans = min(ans, dist);
        }
    }
    cout<<ans;
    return 0;
}