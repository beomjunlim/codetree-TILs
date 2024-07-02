#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    unordered_map<int, int> maps;
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(maps.find(x)!=maps.end()){
            maps[x] = min(maps[x], y);
        }
        else{
            maps[x] = y;
        }
    }

    int ans = 0;

    for(auto it : maps){
        ans += it.second;
    }

    cout<<ans;
    return 0;
}