#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,x;
vector<pair<int,int>> arr[1001];
vector<pair<int,int>> node[1001];
int dist[1001];
int dis[1001];

int main() {
    cin>>n>>m>>x;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a].push_back(make_pair(b,c));
        node[b].push_back(make_pair(a,c));
    }

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    dist[x] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,x));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_idx = pq.top().second;
        pq.pop();

        if(dist[min_idx] < min_dist)
            continue;
        
        for(int i=0; i<arr[min_idx].size(); i++){
            int next_idx = arr[min_idx][i].first;
            int next_dist = arr[min_idx][i].second;

            int new_dist = dist[min_idx] + next_dist;

            if(dist[next_idx] > new_dist){
                dist[next_idx] = new_dist;
                pq.push(make_pair(-new_dist, next_idx));
            }
        }
    }

    for(int i=1; i<=n; i++)
        dis[i] = 987654321;
    dis[x] = 0;

    priority_queue<pair<int,int>> p;
    p.push(make_pair(0,x));

    while(!p.empty()){
        int min_dist = -p.top().first;
        int min_idx = p.top().second;
        p.pop();

        if(dis[min_idx] < min_dist)
            continue;
        
        for(int i=0; i<node[min_idx].size(); i++){
            int next_idx = node[min_idx][i].first;
            int next_dist = node[min_idx][i].second;

            int new_dist = dis[min_idx] + next_dist;

            if(dis[next_idx] > new_dist){
                dis[next_idx] = new_dist;
                p.push(make_pair(-new_dist, next_idx));
            }
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i!=x){
            int sum = dist[i] + dis[i];
            ans = max(ans, sum);
        }
    }

    cout<<ans;

    return 0;
}