#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int main() {
    int n,q;
    cin>>n>>q;

    set<int> num;
    unordered_map<int, int> mapper;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        num.insert(x);
    }

    int cnt = 1;
    for(auto & it: num) {
        mapper[it] = cnt;
        cnt += 1;
    }

    for(int i=0; i<q; i++){
        int x,y;
        cin>>x>>y;
        int num_x = 0;
        if(num.upper_bound(y)==num.end())
            num_x = mapper[*prev(num.end())] + 1;
        else
            num_x = mapper[*num.upper_bound(y)];
        cout<<num_x - mapper[*num.upper_bound(x)]<<'\n';
    }
    return 0;
}