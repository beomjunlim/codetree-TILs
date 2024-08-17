#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,m;
vector<pair<int,pair<int, int>>> v[1001];
int dist[1001];
bool visited[100001];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,make_pair(c,i)));
        v[b].push_back(make_pair(a,make_pair(c,i)));
    }

    for(int i=1; i<=n; i++){
        sort(v[i].begin(), v[i].end());
    }

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[n] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,n));

    while(!pq.empty()){
        int dis = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < dis)
            continue;
        
        for(int i=0; i<v[idx].size(); i++){
            int node = v[idx][i].first;
            int next = v[idx][i].second.first + dis;

            if(dist[node] > next){
                dist[node] = next;
                pq.push(make_pair(-next, node));
            }
        }
    }

    int x = 1;
    while(x!=n){
        for(int i=0; i<v[x].size(); i++){
            if(dist[v[x][i].first] + v[x][i].second.first == dist[x]){
                visited[v[x][i].second.second] = true;
                x = v[x][i].first;
                break;
            }
        }
    }

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[1] = 0;

    pq.push(make_pair(0,1));

    while(!pq.empty()){
        int dis = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < dis)
            continue;
        
        for(int i=0; i<v[idx].size(); i++){
            int node = v[idx][i].first;
            int next = v[idx][i].second.first + dis;
            int index = v[idx][i].second.second;

            if(!visited[index]&&dist[node] > next){
                dist[node] = next;
                pq.push(make_pair(-next, node));
            }
        }
    }

    if(dist[n]==INT_MAX)
        cout<<-1;
    else
        cout<<dist[n];

    return 0;
}