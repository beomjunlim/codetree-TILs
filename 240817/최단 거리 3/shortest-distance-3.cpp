#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n,m;
int dist[1001];
bool visited[1001];
vector<pair<int,int>> v[1001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;

        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    int s,e;
    cin>>s>>e;

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[s] = 0;

    for(int i=1; i<=n; i++){
        int min_idx;
        int min_dist = INT_MAX;

        for(int j=1; j<=n; j++){
            if(!visited[j]&&dist[j]<min_dist){
                min_idx = j;
                min_dist = dist[j];
            }
        }

        visited[min_idx] = true;

        for(int j=0; j<v[min_idx].size(); j++){
            int node = v[min_idx][j].first;
            int next = v[min_idx][j].second + min_dist;

            if(next < dist[node]){
                dist[node] = next;
            }
        }
    }

    cout<<dist[e];
    return 0;
}