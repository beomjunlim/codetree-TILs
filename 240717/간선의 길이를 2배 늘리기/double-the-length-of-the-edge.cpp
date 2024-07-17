#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int arr[251][251];
int dist[251];
int path[251];

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        arr[a][b] = c;
        arr[b][a] = c;
    }

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,1));

    for(int i=1; i<=n; i++)
        dist[i] = 987654321;
    
    dist[1] = 0;

    while(!pq.empty()){
        int min_dist = -pq.top().first;
        int min_idx = pq.top().second;
        pq.pop();

        if(dist[min_idx] < min_dist)
            continue;
        
        for(int i=1; i<=n; i++){
            if(arr[min_idx][i]!=0){
                int next_dist = arr[min_idx][i] + dist[min_idx];

                if(dist[i] > next_dist){
                    path[i] = min_idx;
                    dist[i] = next_dist;
                    pq.push(make_pair(-next_dist, i));
                }
            }
        }
    }

    int cnt = dist[n];
    int ans = 0;
    
    for(int i=2; i<=n; i++){
        int x = i;
        int y = path[i];
        int num = arr[x][y];

        arr[x][y] = 2*num;
        arr[y][x] = 2*num;

        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(0,1));

        for(int i=1; i<=n; i++)
            dist[i] = 987654321;
    
        dist[1] = 0;

        while(!pq.empty()){
            int min_dist = -pq.top().first;
            int min_idx = pq.top().second;
            pq.pop();

            if(dist[min_idx] < min_dist)
                continue;
        
            for(int i=1; i<=n; i++){
                if(arr[min_idx][i]!=0){
                    int next_dist = arr[min_idx][i] + dist[min_idx];

                    if(dist[i] > next_dist){
                        path[i] = min_idx;
                        dist[i] = next_dist;
                        pq.push(make_pair(-next_dist, i));
                    }
                }
            }
        }

        ans = max(ans, dist[n] - cnt);

        arr[x][y] = num;
        arr[y][x] = num;

    }

    cout<<ans;
    return 0;
}