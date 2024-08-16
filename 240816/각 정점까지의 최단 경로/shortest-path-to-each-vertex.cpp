#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int n,m,k;
int dist[20001];
vector<pair<int,int>> v[20001];

int main() {
    cin>>n>>m;
    cin>>k;

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[k] = 0;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(c,b));
        v[b].push_back(make_pair(c,a));
    }

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,k));

    while(!pq.empty()){
        int dis = -pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(dist[node]<dis)
            continue;
        
        for(int i=0; i<v[node].size(); i++){
            int next_node = v[node][i].second;
            int next_dis = dis + v[node][i].first;

            if(next_dis < dist[next_node]){
                dist[next_node] = next_dis;
                pq.push(make_pair(-next_dis, next_node));
            }
        }
    }


    for(int i=1; i<=n; i++){
        if(dist[i]==INT_MAX)
            cout<<-1<<'\n';
        else
            cout<<dist[i]<<'\n';
    }
    return 0;
}