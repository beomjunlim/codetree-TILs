#include <iostream>
#include <vector>
using namespace std;

int n;
int cnt = 0;
vector<int> v[51];
bool visited[51];

void dfs(int num){
    for(int i=0; i<v[num].size(); i++){
        if(!visited[v[num][i]]){
            visited[v[num][i]] = true;
            dfs(v[num][i]);
        }
    }
}

void check(int num){
    bool sw = false;
    for(int i=0; i<v[num].size(); i++){
        if(!visited[v[num][i]]){
            sw = true;
            check(v[num][i]);
        }
    }

    if(!sw){
        cnt++;
    }
}
int main() {
    cin>>n;
    int start = 0;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(x!=-1){
            v[x].push_back(i);
        }
        if(x==-1)
            start = i;
    }

    int a;
    cin>>a;

    visited[a] = true;
    dfs(a);
    if(a!=start)
        check(start);
    cout<<cnt;
    return 0;
}