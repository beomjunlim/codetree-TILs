#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,m,A,B;
int dist[100001][2];
vector<pair<int,int>> v[100001];
void dijkstra(int start, int s){
    for(int i=1; i<=n; i++){
        dist[i][s] = INT_MAX;
    }

    dist[start][s] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx][s] < cnt)
            continue;
        
        for(int i=0; i<v[idx].size(); i++){
            int node = v[idx][i].first;
            int next = v[idx][i].second + cnt;

            if(dist[node][s] > next){
                dist[node][s] = next;
                pq.push(make_pair(-next, node));
            }
        }
    }
}

int main() {
    cin>>n>>m;
    cin>>A>>B;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    dijkstra(A,0);
    dijkstra(B,1);
    int ans = INT_MAX;
    for(int i=1; i<=n; i++){
        if(i!=A&&i!=B){
            if(dist[i][0]!=INT_MAX&&dist[B][0]!=INT_MAX&&dist[i][1]!=INT_MAX)
                ans = min(ans, dist[i][0] + dist[B][0] + dist[i][1]);
            
            if(dist[i][1]!=INT_MAX&&dist[A][1]!=INT_MAX&&dist[i][0]!=INT_MAX)
                ans = min(ans, dist[i][1] + dist[A][1] + dist[i][0]);
        }
    }

    if(ans==INT_MAX)
        ans = -1;
    
    cout<<ans;
    return 0;
}