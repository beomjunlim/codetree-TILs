#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,a,b;
int dist[100001][3]; // i, a, b
vector<pair<int,int>> arr[100001];

void dijkstra(int start, int cnt){
    for(int i=1; i<=n; i++)
        dist[i][cnt] = 987654321;

    dist[start][cnt] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_idx = pq.top().second;
        pq.pop();

        if(dist[min_idx][cnt] < min_dist)
            continue;
        
        for(int i=0; i<arr[min_idx].size(); i++){
            int next_idx = arr[min_idx][i].first;
            int next_dist = arr[min_idx][i].second;

            int new_dist = dist[min_idx][cnt] + next_dist;

            if(dist[next_idx][cnt] > new_dist){
                dist[next_idx][cnt] = new_dist;
                pq.push(make_pair(-new_dist, next_idx));
            }
        }
    }
}
int main() {
    cin>>n>>m;
    cin>>a>>b;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    dijkstra(a,1);
    dijkstra(b,2);
    bool sw = false;
    int ans = 987654321;

    for(int i=1; i<=n; i++){
        if(i!=a&&i!=b){
            bool sw_a = false;
            bool sw_b = false;
            if(dist[i][1]!=987654321&&dist[b][1]!=987654321&&dist[i][2]!=987654321)
                sw_a = true;
            if(dist[i][2]!=987654321&&dist[a][2]!=987654321&&!dist[i][1]!=987654321)
                sw_b = true;
            if(sw_a&&!sw_b){
                int cnt = dist[i][1] + dist[b][1] + dist[i][2];
                ans = min(ans,cnt);
                sw = true;
            }
            else if(!sw_a&&sw_b){
                int cnt = dist[i][2] + dist[a][2] + dist[i][1];
                ans = min(ans,cnt);
                sw = true;
            }
            else if(sw_a&&sw_b){
                int cnt = min(dist[i][1] + dist[b][1] + dist[i][2], dist[i][2] + dist[a][2] + dist[i][1]);
                ans = min(ans,cnt);
                sw = true;
            }
        }
    }
    
    if(!sw)
        ans = -1;
    cout<<ans;
    return 0;
}