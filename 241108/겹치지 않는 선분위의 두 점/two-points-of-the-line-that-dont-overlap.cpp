#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<pair<long long,long long>> v;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    return a.first < b.first;
}

bool Possible(long long dist){
    int cnt = 0;
    long long last = -1000000000000000000;
    for(int i=0; i<m; i++){
        long long a,b;
        a = v[i].first;
        b = v[i].second;

        while(last+dist<=b){
            cnt++;
            last = max(a, last+dist);
            if(cnt>=n)
                break;
        }
    }
    return cnt>=n;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        long long a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), cmp);

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