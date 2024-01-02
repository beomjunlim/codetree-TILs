#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    unordered_map<int,int> m;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;

        if(s=="add"){
            int a,b;
            cin>>a>>b;
            if(m.find(a)!=m.end())
                m[a] = b;
            else
                m.insert({a,b});
        }
        if(s=="find"){
            int a;
            cin>>a;
            if(m.find(a)==m.end())
                cout<<"None"<<'\n';
            else
                cout<<m[a]<<'\n';
        }
        if(s=="remove"){
            int a;
            cin>>a;
            m.erase(a);
        }
    }
    return 0;
}