#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> meets;

    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        meets.push_back(make_pair(s,e));
    }

    sort(meets.begin(), meets.end(), cmp);

    int ans = 1;
    int end = meets[0].second;

    for(int i=1; i<n; i++){
        if(end<=meets[i].first){
            ans++;
            end = meets[i].second;
        }
    }

    cout<<n - ans;
    return 0;
}