#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
vector<pair<int,int>> v[100001];
bool visited[100001];
int dist[100001];

void dfs(int x, int num){
    visited[x] = true;
    for(int i=0; i<v[x].size(); i++){
        if(!visited[v[x][i].first]){
            dist[v[x][i].first] = num + v[x][i].second;
            dfs(v[x][i].first, num + v[x][i].second);
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n-1; i++){
        int x,y,z;
        cin>>x>>y>>z;

        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    dfs(1,0);

    int max_idx = 0;
    int max_num = 0;
    for(int i=1; i<=n; i++){
        if(max_num < dist[i]){
            max_idx = i;
            max_num = dist[i];
        }
    }

    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    dfs(max_idx,0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, dist[i]);
    }

    cout<<ans;
    return 0;
}