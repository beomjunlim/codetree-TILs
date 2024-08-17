#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,m;
int graph[251][251];
int dist[251];
int parent[251];

void dijkstra(int start){
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < cnt)
            continue;
        
        for(int i=1; i<=n; i++){
            if(graph[idx][i]!=0){
                int next = graph[idx][i] + cnt;
                if(dist[i] > next){
                    dist[i] = next;
                    parent[i] = idx;
                    pq.push(make_pair(-next,i));
                }
            }
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a][b] = c;
        graph[b][a] = c;
    }    

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
        parent[i] = 0;
    }

    dijkstra(1);

    int sum = dist[n];

    int x = n;
    int ans = 0;

    while(x!=1){
        int pre = parent[x];
        int num = graph[x][pre];
        graph[x][pre] = 2*num;
        graph[pre][x] = 2*num;

        dijkstra(1);

        int after = dist[n];
        ans = max(ans, after - sum);

        graph[x][pre] = num;
        graph[pre][x] = num;
        x = pre;
    }

    cout<<ans;

    return 0;
}