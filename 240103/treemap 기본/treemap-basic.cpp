#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    map<int,int> m;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="add"){
            int a,b;
            cin>>a>>b;
            m[a] = b;
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
                cout<<m[a]<<'\n';
            else
                cout<<"None"<<'\n';
        }
        if(s=="print_list"){
            if(m.empty())
                cout<<"None"<<'\n';
            else {
                 for(auto & num : m){
                    cout<<num.second<<" ";
                 }
                 cout<<'\n';
            }
        }
    }
    return 0;
}