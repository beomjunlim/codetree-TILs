#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    set<pair<int,int>> s;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        s.insert(make_pair(x,y));
    }

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        auto iter = s.lower_bound(make_pair(x,0));
        if(iter!=s.end()){
            cout<<(*iter).first<<" "<<(*iter).second<<'\n';
            s.erase((*iter));
        }

        else
            cout<<-1<<" "<<-1<<'\n';
    }
    return 0;
}