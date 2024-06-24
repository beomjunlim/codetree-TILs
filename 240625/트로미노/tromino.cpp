#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[201][201];

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m-2; j++){
            ans = max(ans, arr[i][j] + arr[i][j+1] + arr[i][j+2]);
        }
    }

    for(int i=0; i<n-2; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, arr[i][j] + arr[i+1][j] + arr[i+2][j]);
        }
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int temp = arr[i][j] + arr[i+1][j] + arr[i][j+1] + arr[i+1][j+1];
            ans = max(ans, max(temp - arr[i][j], max(temp - arr[i+1][j], max(temp - arr[i][j+1], temp - arr[i+1][j+1]))));
        }
    }

    cout<<ans;
    return 0;
}