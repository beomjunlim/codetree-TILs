#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[100001];
int parent[100001];
vector<int> v[100001];

void find(int x){
    for(int i=0; i<v[x].size(); i++){
        int y = v[x][i];

        if(!visited[y]){
            visited[y] = true;
            parent[y] = x;

            find(y);
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    visited[1] = true;
    find(1);

    for(int i=2; i<=n; i++){
        cout<<parent[i]<<'\n';
    }
    return 0;
}