#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,v,w,e;
int arr[101][101];

int main() {
    cin>>n>>m;
    cin>>v>>w>>e;
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
        arr[b][a] = c;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(arr[i][j] > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }            
            }
        }
    }

    int ans = (int)1e9;

    for(int i=1; i<=n; i++)
        ans = min(ans, arr[v][i] + arr[w][i] + arr[i][e]);

    if(ans==(int)1e9)
        ans = -1;
    cout<<ans;
    return 0;
}