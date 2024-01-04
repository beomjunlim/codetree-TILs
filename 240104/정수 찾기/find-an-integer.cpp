#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> s;
    int n,m;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert(a);
    }

    cin>>m;

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(s.find(a)!=s.end())
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}