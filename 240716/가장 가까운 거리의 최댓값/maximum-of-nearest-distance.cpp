#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n,m,a,b,c;
    vector<pair<int,int>> arr[100001];

    cin>>n>>m;
    cin>>a>>b>>c;

    for(int i=0; i<m; i++){
        int x,y,dis;
        cin>>x>>y>>dis;    
        arr[x].push_back(make_pair(y,dis));
        arr[y].push_back(make_pair(x,dis));
    }

    vector<int> node;

    for(int i=1; i<=n; i++){
        if(i!=a&&i!=b&&i!=c)
            node.push_back(i);
    }

    int dist[100001];
    int ans = 0;

    for(int i=0; i<node.size(); i++){
        int start = node[i];

        for(int j=1; j<=n; j++)
            dist[j] = 987654321;

        dist[start] = 0;

        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(0,start));

        while(!pq.empty()){
            int min_dist = -pq.top().first;
            int min_idx = pq.top().second;
            pq.pop();

            if(dist[min_idx]<min_dist)
                continue;
            
            for(int k=0; k<arr[min_idx].size(); k++){
                int next_idx = arr[min_idx][k].first;
                int next_dist = arr[min_idx][k].second;

                int new_dist = dist[min_idx] + next_dist;
                if(dist[next_idx]>new_dist){
                    dist[next_idx] = new_dist;
                    pq.push(make_pair(-new_dist, next_idx));
                }
            }
        }

        int cost = min(dist[a], min(dist[b], dist[c]));
        ans = max(ans, cost);
    }

    cout<<ans;
    return 0;
}