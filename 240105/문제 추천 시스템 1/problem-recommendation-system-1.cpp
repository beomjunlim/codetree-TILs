#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin>>n;

    set<pair<int,int>> s;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        s.insert(make_pair(b,a));
    }
    int m;
    cin>>m;

    for(int i=0; i<m; i++){
        string str;
        cin>>str;
        if(str=="rc"){
            int x;
            cin>>x;

            if(x==1)
                cout<<(*s.rbegin()).second<<'\n';
            if(x==-1)
                cout<<(*s.begin()).second<<'\n';
        }
        if(str=="ad"){
            int a,b;
            cin>>a>>b;
            s.insert(make_pair(b,a));
        }
        if(str=="sv"){
            int a,b;
            cin>>a>>b;
            s.erase(make_pair(b,a));
        }
    }
    return 0;
}