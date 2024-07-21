#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> bombs;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>b>>a;
        bombs.push_back(make_pair(a,b));
    }

    sort(bombs.begin(), bombs.end(), cmp);

    int end = bombs[0].first;
    int ans = bombs[0].second;

    for(int i=1; i<n; i++){
        if(end<bombs[i].first){
            end = bombs[i].first;
            ans += bombs[i].second;
        }
    }

    cout<<ans;
    return 0;
}