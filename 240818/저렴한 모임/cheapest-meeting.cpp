#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[101][101];

int main() {
    cin>>n>>m;
    int v,u,e;
    cin>>v>>u>>e;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            arr[i][j] = 1e9;
            if(i==j)
                arr[i][j] = 0;
        }
    }

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[x][y] = z;
        arr[y][x] = z;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int ans = 1e9;
    for(int i=1; i<=n; i++){
        ans = min(ans, arr[v][i] + arr[u][i] + arr[i][e]);
    }

    if(ans==1e9)
        ans = -1;
    cout<<ans;
    return 0;
}