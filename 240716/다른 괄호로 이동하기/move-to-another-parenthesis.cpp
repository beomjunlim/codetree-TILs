#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int n,a,b;
char arr[31][31];
int dist[31][31];
bool visited[31][31];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ans = 0;

void dijkstra(int x, int y){
    memset(visited, false, sizeof(visited));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = 987654321;
        }
    }

    dist[x][y] = 0;
    visited[x][y] = true;

    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push(make_pair(0, make_pair(x,y)));

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_x = pq.top().second.first;
        int min_y = pq.top().second.second;
        pq.pop();

        if(dist[min_x][min_y] < min_dist)
            continue;
        
        for(int i=0; i<4; i++){
            int nx = min_x + dx[i];
            int ny = min_y + dy[i];
            int distance;

            if(arr[min_x][min_y]==arr[nx][ny])
                distance = a;
            else
                distance = b;
            int new_distance = distance + dist[min_x][min_y];

            if(!visited[nx][ny]&&dist[nx][ny] > new_distance){
                dist[nx][ny] = new_distance;
                visited[nx][ny] = true;
                pq.push(make_pair(-new_distance, make_pair(nx,ny)));
            } 
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cnt = max(cnt, dist[i][j]);
    ans = max(ans, cnt);
}

int main() {
    cin>>n>>a>>b;
    // same a different b
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int start_x = i;
            int start_y = j;
            dijkstra(start_x, start_y);
        }
    }

    cout<<ans;
    return 0;
}