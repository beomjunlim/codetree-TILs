#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> meet;
    for(int i=0; i<n; i++){
        int s,e;
        cin>>s>>e;
        meet.push_back(make_pair(s,e));
    }

    sort(meet.begin(), meet.end(), cmp);

    int ans = n-1;
    int end = meet[0].second;
    for(int i=1; i<n; i++){
        if(end<=meet[i].first){
            ans--;
            end = meet[i].second;
        }
    }

    cout<<ans;
    return 0;
}