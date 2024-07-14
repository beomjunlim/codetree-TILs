#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    int ans = 987654321;

    ans = min(ans, abs(a-b));
    
    int cnt = 0;
    cnt += abs(a-x);
    cnt += abs(y-b);
    ans = min(ans, cnt);

    cnt = 0;
    cnt += abs(a-y);
    cnt += abs(x-b);
    ans = min(ans, cnt);

    cout<<ans;
    return 0;
}