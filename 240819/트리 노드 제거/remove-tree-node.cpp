#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int root;
int del;
int ans = 0;
int parent[51];
bool visited[51];
vector<int> v[51];

void dfs(int x){
    if(visited[x])
        return;
    
    if(v[x].size()==0)
        ans++;

    for(int i=0; i<v[x].size(); i++){
        int y = v[x][i];

        if(parent[x]==y)
            continue;
        if(visited[y])
            continue;
        dfs(y);
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>parent[i];
        int x= i;
        int y = parent[i];

        if(y==-1)
            root = x;
        else
            v[y].push_back(x);
    }

    cin>>del;
    visited[del] = true;
    
    dfs(root);
    cout<<ans;

    return 0;
}