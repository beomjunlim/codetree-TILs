#include <iostream>
#include <map>
using namespace std;


int main() {
    int n;
    map<int,int> m;
    cin>>n;

    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        if(m.find(a)==m.end())
            m[a]=i;
    }

    for(auto & num : m){
        cout<<num.first<<" "<<num.second<<'\n';
    }
    return 0;
}