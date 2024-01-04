#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    set<int> s;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        s.insert(a);
    }

    for(int i=0; i<m; i++){
        int a;
        cin>>a;
        if(s.lower_bound(a)==s.end())
            cout<<-1<<'\n';
        else
            cout<<*s.lower_bound(a)<<'\n';
    }

    return 0;
}