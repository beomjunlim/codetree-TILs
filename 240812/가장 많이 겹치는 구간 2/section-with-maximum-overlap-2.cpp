#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> num;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;

        num.push_back(make_pair(x,1));
        num.push_back(make_pair(y,-1));
    }

    sort(num.begin(), num.end());

    int cnt = 0;
    int ans = 0;
    for(int i=0; i<2*n; i++){
        cnt += num[i].second;
        ans = max(ans, cnt);
    }

    cout<<ans;
    return 0;
}