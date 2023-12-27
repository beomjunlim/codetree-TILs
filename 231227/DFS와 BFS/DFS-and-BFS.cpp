#include <iostream>
#include <queue>
using namespace std;

#define MAX 1001

int n,m;
int graph[MAX][MAX] = {0, };
bool visited[MAX] = {false, };

void clear(){
    for(int i=1; i<=n; i++){
        visited[i] = false;
    }
}

void dfs(int num){
    visited[num] = true;
    cout<<num<<" ";
    for(int i=1; i<=n; i++){
        if(graph[num][i]==1 && !visited[i]){
            dfs(i);
        }
    }
}

void bfs(int num){
    queue<int> q;
    visited[num] = true;
    q.push(num);
    cout<<num<<" ";

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=1; i<=n; i++){
            if(graph[node][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
                cout<<i<<" ";
            }
        }
    }
}

int main() {
    int t;
    cin>>n>>m>>t;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(t);
    clear();
    cout<<'\n';
    bfs(t);

    return 0;
}