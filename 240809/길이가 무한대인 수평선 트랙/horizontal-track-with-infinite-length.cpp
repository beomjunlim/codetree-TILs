#include <iostream>
#include <set>
using namespace std;

int main() {
    int n,t;
    cin>>n>>t;

    set<long long> s;

    for(int i=0; i<n; i++){
        long long a,b;
        cin>>a>>b;
        long long target = a + b*t;

        while(true){
            auto it = s.lower_bound(target);
            if(it==s.end())
                break;
            s.erase(it);
        }
        s.insert(target);
    }
    

    cout<<s.size();
    return 0;
}