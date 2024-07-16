#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m,a,b,c;
vector<pair<int,int>> arr[100001];
int dist[100001][3];

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
                pq.push(make_pair(-new_dist,next_idx));
            }
        }
    }
}

int main() {
    cin>>n>>m;
    cin>>a>>b>>c;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;    
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    dijkstra(a,0);
    dijkstra(b,1);
    dijkstra(c,2);

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i!=a&&i!=b&&i!=c){
            int cnt = min(dist[i][0], min(dist[i][1], dist[i][2]));
            ans = max(ans, cnt);
        }
    }

    cout<<ans;
    return 0;
}