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
        auto iter = s.upper_bound(a);
        if(iter==s.begin()&&a<(*s.upper_bound(a)))
            cout<<-1<<'\n';
        else{
            iter = prev(iter);
            cout<<(*iter)<<'\n';
            s.erase((*iter));
        }
    }
    return 0;
}