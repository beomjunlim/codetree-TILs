#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,1));
        v.push_back(make_pair(y,-1));
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    int ans = 0;
    for(int i=0; i<2*n; i++){
        if(v[i].second==1){
            cnt++;
            ans = max(ans, cnt);
        }
        else{
            cnt--;
        }
    }

    cout<<ans;
    return 0;
}