#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[101][101]={0};
int dist[101];
bool visited[101];

void dijkstra(int x){
    for(int i=2; i<=n; i++){
        if(x!=i&&arr[x][i]!=0){
            dist[i] = min(dist[i], arr[x][i] + dist[x]);
        }
    }
}
int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x][y] = dis;
    }


    dist[1] = 0;
    
    for(int i=2; i<=n; i++){
        if(arr[1][i]!=0){
            dist[i] = arr[1][i];
        }
        else
            dist[i] = 987654321;
    }
    
    for(int i=1; i<n; i++){
        int x = 987654321;
        int idx;
        for(int j=2; j<=n; j++){
            if(!visited[j]&&x>dist[j]){
                visited[j] = true;
                idx = j;
                x= dist[j];
            }
        }

        dijkstra(idx);
    }
    
    for(int i=2; i<=n; i++){
        if(dist[i]==987654321)
            cout<<-1<<'\n';
        else
            cout<<dist[i]<<'\n';
    }
    return 0;
}