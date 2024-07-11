#include <iostream>
#include <vector>
using namespace std;

int n;
vector<pair<int,int>> arr[100001];
bool visited[100001];
int dist[100001];

void dfs(int num, int cnt){
    for(int i=0; i<arr[num].size(); i++){
        if(!visited[arr[num][i].first]){
            visited[arr[num][i].first] = true;
            dist[arr[num][i].first] = cnt + arr[num][i].second;
            dfs(arr[num][i].first, dist[arr[num][i].first]);
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    
    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    dist[1] = 0;
    visited[1] = true;
    dfs(1,0);

    int far_dist = -1;
    int far_vertex = -1;
    for(int i=1; i<=n; i++){
        if(dist[i]>far_dist){
            far_vertex = i;
            far_dist = dist[i];
        }
    }

    for(int i=1; i<=n; i++){
        visited[i] = false;
        dist[i] = 0;
    }

    dist[far_vertex] = 0;
    visited[far_vertex] = true;
    dfs(far_vertex,0);

    far_dist = -1;
    far_vertex = -1;
    for(int i=1; i<=n; i++){
        if(dist[i]>far_dist){
            far_vertex = i;
            far_dist = dist[i];
        }
    }

    cout<<far_dist;
    return 0;
}