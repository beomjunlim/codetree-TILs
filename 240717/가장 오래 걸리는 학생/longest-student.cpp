#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> node[100001];
    int dist[100001];

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        node[a].push_back(make_pair(b,c));
        node[b].push_back(make_pair(a,c));
    }

    for(int i=1; i<n; i++)
        dist[i] = 987654321;
    
    dist[n] = 0 ;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_idx = pq.top().second;
        pq.pop();

        if(dist[min_idx] < min_dist)
            continue;
        
        for(int i=0; i<node[min_idx].size(); i++){
            int next_idx = node[min_idx][i].first;
            int next_dist = node[min_idx][i].second + dist[min_idx];

            if(dist[next_idx] > next_dist){
                dist[next_idx] = next_dist;
                pq.push(make_pair(-next_dist, next_idx));
            }
        }
    }

    int ans = 0;
    for(int i=1; i<n; i++)
        ans = max(ans, dist[i]);
    
    cout<<ans;
    return 0;
}