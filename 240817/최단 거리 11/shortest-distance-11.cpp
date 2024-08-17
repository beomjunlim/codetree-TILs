#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>
using namespace std;

int n,m;
bool visited[1001];
int arr[1001][1001];
int pre[1001];
int dist[1001];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[x][y] = z;
        arr[y][x] = z;
    }

    int s,e;
    cin>>s>>e;

    for(int i=1; i<=n; i++){
        dist[i] = INT_MAX;
        pre[i] = 0;
    }

    dist[e] = 0;

    for(int i=1; i<=n; i++){
        int min_idx = n + 1;
        int min_dist = INT_MAX;

        for(int j=1; j<=n; j++){
            if(!visited[j]&&dist[j]<min_dist){
                min_idx = j;
                min_dist = dist[j];
            }
        }

        visited[min_idx] = true;

        for(int j=1; j<=n; j++){
            if(arr[min_idx][j]!=0){
                int node = j;
                int next_dist = min_dist + arr[min_idx][j];

                if(dist[j] > next_dist){
                    dist[j] = next_dist;
                }
            }
        }
    }

    cout<<dist[s]<<'\n';

    cout<<s<<" ";
    int x = s;
    while(x!=e){
        for(int i=1; i<=n; i++){
            if(arr[i][x]!=0&&dist[i] + arr[i][x] == dist[x]){
                x = i;
                break;
            }
        }
        cout<<x<<" ";
    }
    return 0;
}