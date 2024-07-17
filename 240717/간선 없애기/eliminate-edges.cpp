#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
int arr[1001][1001];
int dist[1001];
int path[1001];
bool visited[1001];

void dijkstra(){
    memset(visited, false, sizeof(visited));
    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    dist[1] = 0;

    for(int i=1; i<=n; i++){
        int x = 987654321;
        int idx = -1;

        for(int j=1; j<=n; j++){
            if(!visited[j]&&dist[j] < x){
                idx = j;
                x = dist[j];
            }
        }

        if(idx==-1)
            break;
        
        visited[idx] = true;

        for(int j=1; j<=n; j++){
            if(!visited[j]&&arr[idx][j]!=0&&dist[j] > dist[idx] + arr[idx][j]){
                dist[j] = dist[idx] + arr[idx][j];
                path[j] = idx;
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b] = c;
        arr[b][a] = c;
    }

    dijkstra();
    int num = dist[n];
    vector<pair<int,int>> v; 
    int ans = 0;
    int idx = n;
    while(true){
        int a = path[idx];
        v.push_back(make_pair(a,idx));
        idx = a;
        if(idx==1)
            break;
    }

    for(int i=0; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        int number = arr[x][y];

        arr[x][y] = 0;
        arr[y][x] = 0;

        dijkstra();
        
        if(num!=dist[n])
            ans++;
        

        arr[x][y] = number;
        arr[y][x] = number;
    }

    cout<<ans;
    return 0;
}