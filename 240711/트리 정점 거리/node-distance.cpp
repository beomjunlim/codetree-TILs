#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
int ans = 0;
vector<pair<int,int>> v[1001];
int dist[1001][1001];
bool visited[1001];

void dfs(int x, int y, int sum){
    if(x==y)
        ans = sum;

    for(int i=0; i<v[x].size(); i++){
        int num = v[x][i].first;
        int cnt = v[x][i].second;
        if(!visited[num]){
            visited[num] = true;
            dfs(num, y, sum + cnt);
        }
    }

}
int main() {
    cin>>m>>n;

    for(int i=0; i<m-1; i++){
        int x,y,z;
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }

    for(int i=0; i<n; i++){
        memset(visited, false, sizeof(visited));
        int x,y;
        cin>>x>>y;
        dfs(x,y,0);
        cout<<ans<<'\n';
    }
    return 0;
}