#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;

    set<int> s;
    s.insert(0);

    int ans = 1e9;

    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        auto it = s.upper_bound(num);
        if(it==s.end()){
            int A = *s.rbegin();
            ans = min(ans, abs(num-A));
        }
        else{
            int A = *it;
            if(it!=s.begin()){
                int B = *prev(it);
                ans = min(ans, abs(num-B));
            }
            ans = min(ans, abs(num-A));
        }
        s.insert(num);
        cout<<ans<<'\n';
    }
    return 0;
}