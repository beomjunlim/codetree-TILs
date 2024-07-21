#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 1;
    int end = v[0].second;

    for(int i=1; i<n; i++){
        if(v[i].first>=end){
            ans++;
            end = v[i].second;
        }
    }

    cout<<ans;
    return 0;
}