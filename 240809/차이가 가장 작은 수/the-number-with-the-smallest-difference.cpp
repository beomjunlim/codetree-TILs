#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;

    set<int> s;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        s.insert(num);
    }

    int ans = 1e9;
    auto A = s.begin();
    auto B = next(A);

    while(B!=s.end()){
        int a = *A;
        int b = *B;

        if(b-a<m)
            B++;
        else{
            ans = min(ans, b-a);
            A++;
        }
    }

    if(ans==1e9)
        ans = -1;
    cout<<ans;
    return 0;
}