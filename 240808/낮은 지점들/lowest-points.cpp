#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin>>n;

    unordered_map<long long, long long> num;
    for(int i=0; i<n; i++){
        long long x,y;
        cin>>x>>y;

        if(num.find(x)==num.end())
            num[x] = y;
        else if(num[x]>y)
            num[x] = y;
    }

    long long ans = 0;

    for(auto it : num)
        ans += it.second;
    
    cout<<ans;
    return 0;
}