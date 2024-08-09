#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    set<int> s;
    for(int i=0; i<=n; i++)
        s.insert(i);
    
    for(int i=0; i<m; i++){
        int num;
        cin>>num;
        s.erase(num);
        int ans = 0;
        int temp = 1;
        auto it = s.begin();
        int A = *it;
        while(it!=s.end()){
            it++;
            int B = *it;
            if(A+1==B)
                temp++;

            else{
                ans = max(ans, temp);
                temp = 1;
            }
            A = B;
        }
        cout<<ans<<'\n';
    }
    return 0;
}