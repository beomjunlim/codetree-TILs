#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    unordered_map<long long, long long> maps;
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        if(maps.find(x)!=maps.end()){
            if(maps[x]>y)
                maps[x] = y;
        }
        else{
            maps[x] = y;
        }
    }

    long long ans = 0;

    for(auto it : maps){
        ans += it.second;
    }

    cout<<ans;
    return 0;
}