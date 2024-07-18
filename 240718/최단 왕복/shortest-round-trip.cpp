#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    int arr[101][101];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = (int)1e9;
        }
        arr[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    long long ans = (int)1e9;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j){
                long long cnt = arr[i][j] + arr[j][i];
                ans = min(ans ,cnt);
            }
        }
    }

    cout<<ans;
    return 0;
}