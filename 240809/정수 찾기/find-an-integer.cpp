#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,m;
    cin>>n;

    unordered_set<int> sets;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        sets.insert(num);
    }

    cin>>m;
    
    for(int i=0; i<m; i++){
        int num;
        cin>>num;

        if(sets.find(num)!=sets.end())
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}