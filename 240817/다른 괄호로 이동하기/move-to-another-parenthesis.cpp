#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n,A,B;
char arr[31][31];
int node_num[31][31];
vector<pair<int,int>> graph[1001];
int dist[1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void dijkstra(int start){
    for(int i=1; i<=n*n; i++){
        dist[i] = INT_MAX;
    }

    dist[start] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < min_dist)
            continue;

        for(int i=0; i<graph[idx].size(); i++){
            int node = graph[idx][i].first;
            int next = graph[idx][i].second + min_dist;

            if(dist[node] > next){
                dist[node] = next;
                pq.push(make_pair(-next, node));
            }
        }
    }
}
int main() {
    cin>>n>>A>>B;

    int idx = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            node_num[i][j] = idx;
            idx++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<4; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(InRange(nx,ny)){
                    int node1 = node_num[i][j];
                    int node2 = node_num[nx][ny];
                    int cost = (arr[i][j]==arr[nx][ny]) ? A : B;
                    graph[node1].push_back(make_pair(node2, cost));
                }
            }   
        }
    }

    int ans = 0;
    for(int i=1; i<=n*n; i++){
        dijkstra(i);

        for(int j=1; j<=n*n; j++){
            ans = max(ans, dist[j]);
        }
    }
    cout<<ans;
    return 0;
}