#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    unordered_set<int> m;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="add"){
            int a;
            cin>>a;
            if(m.find(a)!=m.end())
                continue;
            else
                m.insert(a);
        }
        if(s=="remove"){
            int a;
            cin>>a;
            m.erase(a);
        }
        if(s=="find"){
            int a;
            cin>>a;
            if(m.find(a)!=m.end())
                cout<<"true"<<'\n';
            else
                cout<<"false"<<'\n';
        }
    }
    return 0;
}