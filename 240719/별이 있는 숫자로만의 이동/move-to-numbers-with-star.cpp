#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
int arr[401][401];

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=n;
}

int GetArea(int x, int y) {
    int sum = 0;
    for (int i = max(1, x - m); i <= min(n, x + m); i++) {
        for (int j = max(1, y - m); j <= min(n, y + m); j++) {
            if (abs(x - i) + abs(y - j) <= m) {
                sum += arr[i][j];
            }
        }
    }
    return sum;
}

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }    

    int ans = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            ans = max(ans, GetArea(i,j));
        }
    }

    cout<<ans;
   return 0;
}