#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    unordered_map<int,int> maps;
    int size = 0;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        maps[y] = x;
        size = max(size,y);
    }

    int ans = 0;

    for(int i=0; i<=size; i++){
        int sum = 0;
        for(int j=i; j<=i+k; j++){
            if(maps.find(j)!=maps.end())
                sum += maps[j];
        }

        for(int j=i; j>=i-k; j--){
            if(maps.find(j)!=maps.end())
                sum += maps[j];
        }
        sum -= maps[i];
        ans = max(ans, sum);
    }

    cout<<ans;
    return 0;
}