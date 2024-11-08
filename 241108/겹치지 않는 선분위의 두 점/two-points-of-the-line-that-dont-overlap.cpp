#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<pair<long long,long long>> v;

bool Possible(long long dist){
    long long last =v[0].first;
    int cnt = 1;
    int idx = 0;

    while(idx<m){
        if(last+dist<=v[idx].second){
            last = last + dist;
            cnt++;
            if(cnt==n)
                return true;
        }
        else
            idx++;
    }
    return false;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        long long a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    long long left = 0;
    long long right = 1000000000000000000;
    long long ans = 0;

    while(left<=right){
        long long mid = (left + right)/2;

        if(Possible(mid)){
            left = mid + 1;
            ans = max(ans, mid);
        }
        else
            right = mid - 1;
    }

    cout<<ans;
    return 0;
}