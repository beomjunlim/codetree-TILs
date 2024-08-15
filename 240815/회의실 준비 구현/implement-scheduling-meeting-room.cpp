#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
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


    int end = v[0].second;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(v[i].first>=end){
            ans++;
            end = v[i].second;
        }
    }

    cout<<ans;
    return 0;
}