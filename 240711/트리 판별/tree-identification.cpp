#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
vector<int> tree[10001];
int deg[100001];
bool used[10001];
bool visited[10001];
int root = -1;

bool find_root(){
    vector<int> v;
    for(int i=1; i<=n; i++){
        if(used[i]&&deg[i]==0)
            v.push_back(i);
    }

    if(v.size()!=1)
        return false;
    else{
        root = v[0];
        return true;
    }
}

void dfs(int x){
    for(int i=0; i<tree[x].size(); i++){
        int y= tree[x][i];
        if(!visited[y]){
            visited[y] = true;
            dfs(y);
        }
    }
}

int main() {
    cin>>m;

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        n = max(n, max(x,y));
        used[x] = used[y] = true;
        deg[y]++;
    }

    int ans;

    if(!find_root())
        ans = 0;
    else{
        bool sw = true;
        for(int i=1; i<=n; i++){
            if(i!=root&&used[i]&&deg[i]!=1)
                sw = false;
        }

        if(!sw)
            ans = 0;
        else{
            visited[root] = true;
            dfs(root);

            bool sw_a = true;
            for(int i=1; i<=n; i++){
                if(used[i]&&!visited[i])
                    sw_a = false;
            }

            if(!sw_a)
                ans = 0;
            else
                ans = 1;
        }
    }
   cout<<ans;
    return 0;
}