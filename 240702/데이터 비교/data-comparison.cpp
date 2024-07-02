#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n,m;
    unordered_set<long long> sets;
    cin>>n;

    for(int i=0; i<n; i++){
        long long a;
        cin>>a;
        sets.insert(a);
    }

    cin>>m;

    for(int i=0; i<m; i++){
        long long a;
        cin>>a;

        if(sets.find(a)!=sets.end()){
            cout<<1<<" ";
        }
        else{
            cout<<0<<" ";
        }
    }
    return 0;
}