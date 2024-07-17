#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int dist[101][101];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = (int)1e9;
        }
        dist[i][i] = 0;
    }

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        dist[a][b] = min(dist[a][b],c);
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j]==(int)1e9)
                cout<<-1<<" ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}