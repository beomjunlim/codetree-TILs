#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int n,m,x;
int A[1001][1001];
int B[1001][1001];
int dist[1001];
int dist_a[1001];

void dijkstra(int start){
    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
        dist_a[i] = INT_MAX;
    }

    dist[start] = 0;
    dist_a[start] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist[idx] < cnt)
            continue;
        
        for(int i=1; i<=n; i++){
            if(A[idx][i]!=0){
                int next= A[idx][i] + cnt;

                if(dist[i]>next){
                    dist[i] = next;
                    pq.push(make_pair(-next, i));
                }
            }
        }
    }

    pq.push(make_pair(0,start));

    while(!pq.empty()){
        int cnt = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        if(dist_a[idx] < cnt)
            continue;
        
        for(int i=1; i<=n; i++){
            if(B[idx][i]!=0){
                int next= B[idx][i] + cnt;

                if(dist_a[i]>next){
                    dist_a[i] = next;
                    pq.push(make_pair(-next, i));
                }
            }
        }
    }


}
int main() {
    cin>>n>>m>>x;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;

        A[x][y] = z;
        B[y][x] = z;
    }

    dijkstra(x);

    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i!=x){
            ans = max(ans, dist[i] + dist_a[i]);
        }
    }

    cout<<ans;
    return 0;
}