#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int dist[100001];
vector<pair<int,int>> v[100001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[y].push_back(make_pair(x,z));
    }    

    for(int i=1; i<=n; i++){
        dist[i] = 1e9;
    }

    dist[n] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int dis = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[node] < dis)
            continue;

        for(int i=0; i<v[node].size(); i++){
            int next = v[node][i].first;
            int new_dist  = v[node][i].second + dis;

            if(dist[next] > new_dist){
                dist[next] = new_dist;
                pq.push(make_pair(-new_dist, next));
            }
        }
    }

    int ans = 0;
    for(int i=1; i<n; i++){
        ans = max(ans, dist[i]);
    }

    cout<<ans;
    return 0;
}