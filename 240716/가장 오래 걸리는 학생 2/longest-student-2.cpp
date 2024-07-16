#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n,m;
vector<pair<int,int>> arr[100001];
int dist[100001];

int main() {
    int n,m;
    int ans = 0;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        arr[y].push_back(make_pair(x,dis));
    }

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    
    dist[n] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int min_dist= -pq.top().first;
        int min_index = pq.top().second;
        pq.pop();

        if(min_dist > dist[min_index])
            continue;
        
        for(int i=0; i<arr[min_index].size(); i++){
            int next_index = arr[min_index][i].first;
            int next_dist = arr[min_index][i].second;

            int new_dist = dist[min_index] + next_dist;

            if(dist[next_index] > new_dist){
                dist[next_index] = new_dist;
                pq.push(make_pair(-new_dist, next_index));
            }
        }
    }

    for(int i=1; i<n; i++)
        ans = max(ans, dist[i]);

    cout<<ans;
    return 0;
}