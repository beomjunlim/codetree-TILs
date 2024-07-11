#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int m;
vector<int> tree[1001];
bool visited[1001];
int root = -1;

bool find_root(){
    for(int i=1; i<=m; i++){
        for(int j=0; j<tree[i].size(); j++){
            visited[tree[i][j]] = true;
        }
    }

    vector<int> v;
    for(int i=1; i<=m; i++){
        if(!visited[i]){
            v.push_back(i);
        }
    }

    if(v.size()!=1)
        return false;
    else{
        root = v[0];
        return true;
    }
}

void dfs(int x){
    visited[x] = true;
    for(int i=0; i<tree[x].size(); i++){
        int num = tree[x][i];
        if(!visited[num]){
            dfs(num);
        }
    }
}

int main() {
    cin>>m;

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
    }

    int ans;

    if(!find_root())
        ans = 0;
    else{
        memset(visited, false, sizeof(visited));
        dfs(root);
        bool sw = false;

        for(int i=1; i<=m; i++){
            if(!visited[i]){
                sw = true;
                break;
            }
        }

        if(sw)
            ans = 0;
        else
            ans = 1;
    }

    cout<<ans;
    return 0;
}