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
        int num_x = mapper[*num.lower_bound(x)];
        int num_y = mapper[*num.upper_bound(y)];
        // if(num.lower_bound(x)==num.end()){
        //     cout<<0<<'\n'; // 1
        //     continue;
        // }
        
        // if(num.lower_bound(y)!=num.find(y)&&num.lower_bound(y)==num.begin()){
        //     cout<<0<<'\n'; // 2
        //     continue;
        // }

        // else if(num.lower_bound(x)!=num.find(x)&&num.lower_bound(x)==num.begin())
        //     num_x = 0;
        // else 
        //     num_x = mapper[*prev(num.lower_bound(x))];


        // if(num.lower_bound(y)==num.end())
        //     num_y = mapper[*prev(num.end())];
        // else if(num.find(y)==num.lower_bound(y))
        //     num_y = mapper[*num.lower_bound(y)];
        // else
        //     num_y = mapper[*prev(num.lower_bound(y))];

        cout<<num_y - num_x<<'\n';
    }
    return 0;
}