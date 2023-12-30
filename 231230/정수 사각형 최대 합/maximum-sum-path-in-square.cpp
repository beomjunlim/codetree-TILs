#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX][MAX];
int ans[MAX][MAX];

int main() {
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    ans[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        ans[0][i] = ans[0][i-1] + arr[0][i];
        ans[i][0] = ans[i-1][0] + arr[i][0];
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            ans[i][j] = (max(ans[i-1][j], ans[i][j-1]) + arr[i][j]);
        }
    }

    cout<<ans[n-1][n-1];
    return 0;
}