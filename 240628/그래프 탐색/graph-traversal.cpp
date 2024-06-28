#include <iostream>
#include <vector>
using namespace std;

int n,m;
int ans = 0 ;
vector<int> node[1001];
bool visited[1001];

void dfs(int num){
    for(int i=0; i<node[num].size(); i++){
        int number = node[num][i];
        if(!visited[number]){
            visited[number] = true;
            ans++;
            dfs(number);
        }
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }

    visited[1] = true;
    dfs(1);
    cout<<ans;
    return 0;
}