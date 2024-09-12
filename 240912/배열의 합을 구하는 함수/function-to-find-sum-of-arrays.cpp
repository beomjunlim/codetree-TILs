#include <iostream>
using namespace std;

int arr[11][11];
int ans[12][12];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            temp += arr[i][j];
            ans[i][j] = arr[i][j];
        }
        ans[i][n] = temp;
    }

    int tmp = 0;
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<n; j++){
            temp += arr[j][i];
        }
        ans[n][i] = temp;
        tmp += ans[n][i];
    }

    ans[n][n] = tmp;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}