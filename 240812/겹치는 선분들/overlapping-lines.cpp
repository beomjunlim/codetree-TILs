#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> num;

    int idx = 0;
    for(int i=0; i<n; i++){
        int a;
        char b;
        cin>>a>>b;

        if(b=='R'){
            num.push_back(make_pair(idx,1));
            num.push_back(make_pair(idx+a,-1));
            idx+=a;
        }

        if(b=='L'){
            num.push_back(make_pair(idx-a,1));
            num.push_back(make_pair(idx,-1));
            idx-=a;
        }
    }

    sort(num.begin(), num.end());

    int ans = 0;
    int sum = 0;
    for(int i=0; i<2*n; i++){
        int x = num[i].first;
        int y = num[i].second;

        if(sum>=k){
            int prev_x = num[i-1].first;
            ans += x - prev_x;
        }
        sum += y;
    }

    cout<<ans;
    return 0;
}