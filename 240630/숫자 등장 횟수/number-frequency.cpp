#include <iostream>
#include <unordered_map>
using namespace std;

int ans[100001];

int main() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> maps;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        maps[a]++;
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        ans[i] = maps[a];
        cout<<ans[i]<<" ";
    }

    return 0;
}