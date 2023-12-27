#include <iostream>
#include <queue>
using namespace std;

#define MAX 101

int n, m;
int graph[MAX][MAX] = {0, };
bool visited[MAX] = {false, };

int bfs(int num){
    int cnt=0;
    queue<int> q;
    q.push(num);
    visited[num] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[node][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    cout<<bfs(1);
    return 0;
}