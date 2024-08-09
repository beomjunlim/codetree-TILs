#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    set<int> s;
    for(int i=1 ; i<=m; i++){
        s.insert(-i);
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        num = -num;
        auto it = s.lower_bound(num);
        if(it!=s.end()){
            s.erase(*it);
            ans++;
        }
        else{
            break;
        }
    }

    cout<<ans;
    return 0;
}