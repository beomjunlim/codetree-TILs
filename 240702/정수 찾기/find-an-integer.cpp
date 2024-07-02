#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,m;
    unordered_set<int> sets;

    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        sets.insert(a);
    }

    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(sets.find(a)!=sets.end()){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
    return 0;
}