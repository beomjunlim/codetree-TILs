#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> m;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="add"){
            int x;
            cin>>x;
            if(m.find(x)!=m.end())
                continue;
            m.insert(x);
        }
        if(s=="remove"){
            int x;
            cin>>x;
            m.erase(x);
        }
        if(s=="find"){
            int x;
            cin>>x;
            if(m.find(x)!=m.end())
                cout<<"true"<<'\n';
            else
                cout<<"false"<<'\n';
        }
        if(s=="lower_bound"){
            int x;
            cin>>x;
            if(m.lower_bound(x)==m.end())
                cout<<"None"<<'\n';
            else
                cout<<*m.lower_bound(x)<<'\n';
        }
        if(s=="upper_bound"){
            int x;
            cin>>x;
            if(m.upper_bound(x)==m.end())
                cout<<"None"<<'\n';
            else
                cout<<*m.upper_bound(x)<<'\n';
        }
        if(s=="largest"){
            if(!m.empty())
                cout<<*m.rbegin()<<'\n';
            else
                cout<<"None"<<'\n';
        }
        if(s=="smallest"){
            if(!m.empty())
                cout<<*m.begin()<<'\n';
            else
                cout<<"None"<<'\n';
        }
    }
    return 0;
}