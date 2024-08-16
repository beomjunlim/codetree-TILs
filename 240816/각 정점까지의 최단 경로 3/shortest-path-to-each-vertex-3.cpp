#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n,m;
int cost[101];
bool visited[101];
vector<pair<int,int>> v[101];

int main() {
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cost[i] = INT_MAX;
    }

    cost[1] = 0;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));

        if(a==1){
            cost[b] = c;
        }
    }

    // priority_queue<pair<int,int>> pq;

    // for(int i=2; i<=n; i++){
    //     if(cost[i]!=INT_MAX){
    //         pq.push(make_pair(-cost[i], i));
    //     }
    // }

    // while(!pq.empty()){
    //     int dist = -pq.top().first;
    //     int node = pq.top().second;
    //     pq.pop();

    //     if(cost[node]<dist)
    //         continue;
        
    //     for(int i=0; i<v[node].size(); i++){
    //         int next_node = v[node][i].first;
    //         int next_dist = v[node][i].second;

    //         if(next_dist + dist < cost[next_node]){
    //             cost[next_node] = next_dist + dist;
    //             pq.push(make_pair(-cost[next_node], next_node));
    //         }
    //     }
    // }
    for(int i=1; i<=n; i++){
        
        int min_idx;
        int dist = INT_MAX;
        for(int j=1; j<=n; j++){
            if(!visited[j]&&cost[j]<dist){
                min_idx = j;
                dist = cost[j];
            }
        }

        visited[min_idx] = true;

        for(int j=0; j<v[min_idx].size(); j++){
            cost[v[min_idx][j].first] = min(cost[v[min_idx][j].first], cost[min_idx] + v[min_idx][j].second);
        }
    }

    for(int i=2; i<=n; i++){
        if(cost[i]==INT_MAX)
            cout<<-1<<'\n';
        else
            cout<<cost[i]<<'\n';
    }
    return 0;
}