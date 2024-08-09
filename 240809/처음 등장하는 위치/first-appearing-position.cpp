#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin>>n;

    map<int,int> num;

    for(int i=1; i<=n; i++){
        int a;
        cin>>a;
        if(num.find(a)!=num.end())
            continue;
        num[a] = i;
    }

    for(auto it : num){
        cout<<it.first<<" "<<it.second<<'\n';
    }
    return 0;
}