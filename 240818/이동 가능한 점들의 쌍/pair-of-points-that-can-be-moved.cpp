#include <iostream>
#include <algorithm>
using namespace std;

int n,m,p,q;
int arr[201][201];
bool visited[201][201];

int main() {
    cin>>n>>m>>p>>q;

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

    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    long long ans = 0;
    int cnt = 0;
    for(int i=0; i<q; i++){
        int s,e;
        cin>>s>>e;

        int dis = 1e9;
        for(int j=1; j<=p; j++){
            dis = min(dis, arr[s][j] + arr[j][e]);
        }

        if(dis>=1e9)
            continue;
        ans += dis;
        cnt++;
    }

    cout<<cnt<<'\n';
    cout<<ans;
    return 0;
}