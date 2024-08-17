#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,m;
vector<pair<int,int>> v[100001];
int dist[100001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;

        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[n] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < cnt)
            continue;

        for(int i=0; i<v[idx].size(); i++){
            int node = v[idx][i].first;
            int next = v[idx][i].second + cnt;

            if(dist[node] > next){
                dist[node] = next;
                pq.push(make_pair(-next, node));
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