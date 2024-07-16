#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m;
    vector<pair<int,int>> arr[1001];
    int dist[1001];

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    int start,end;
    cin>>start>>end;

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    
    dist[start] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

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

    cout<<dist[end];
    return 0;
}