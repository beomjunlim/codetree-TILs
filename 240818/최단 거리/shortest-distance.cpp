#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[101][101];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        cout<<arr[a][b]<<'\n';
    }
    return 0;
}