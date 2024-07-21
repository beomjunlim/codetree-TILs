#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> bombs;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b; // score time
        bombs.push_back(make_pair(a,b));
    }

    sort(bombs.begin(), bombs.end(), cmp);

    priority_queue<int>pq;
    int bomb_idx = 0;
    int ans = 0;
    
    for(int t=10000; t>=1; t--){
        while(bomb_idx<n&&bombs[bomb_idx].second>=t){
            pq.push(bombs[bomb_idx].first);
            bomb_idx++;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout<<ans;
    return 0;
}