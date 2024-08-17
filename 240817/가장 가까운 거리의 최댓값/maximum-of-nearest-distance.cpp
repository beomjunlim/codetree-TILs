#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int cost[100001][3];
vector<pair<int,int>> v[100001];

void dijstra(int num,int cnt){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,num));

    while(!pq.empty()){
        int dist = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(cost[node][cnt] < dist)
            continue;
        
        for(int i=0; i<v[node].size(); i++){
            int idx = v[node][i].first;
            int next = v[node][i].second + dist;

            if(cost[idx][cnt] > next){
                cost[idx][cnt] = next;
                pq.push(make_pair(-next, idx));
            }
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    int a,b,c;
    cin>>a>>b>>c;

    for(int i=0; i<m; i++){
        int s,e,d;
        cin>>s>>e>>d;
        v[s].push_back(make_pair(e,d));
        v[e].push_back(make_pair(s,d));
    }

    for(int i=1; i<=n; i++){
        cost[i][0] = cost[i][1] = cost[i][2] = INT_MAX;
    }

    cost[a][0] = 0;
    cost[b][1] = 0;
    cost[c][2] = 0;

    dijstra(a,0);
    dijstra(b,1);
    dijstra(c,2);

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i!=a&&i!=b&&i!=c){
            int num = min(cost[i][0], min(cost[i][1], cost[i][2]));
            ans = max(ans, num);
        }
    }

    cout<<ans;
    return 0;
}