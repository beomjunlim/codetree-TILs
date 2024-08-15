#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main() {
    int n;
    cin>>n;

    int max_time = 0;
    vector<pair<int,int>> bomb;
    for(int i=0; i<n; i++){
        int score,time;
        cin>>score>>time;
        bomb.push_back(make_pair(time, score));
        max_time = max(max_time, time);
    }

    sort(bomb.begin(), bomb.end());

    priority_queue<int> pq;
    int idx = n-1;
    int ans = 0;

    for(int i=max_time; i>0; i--){
        while(idx>=0&&bomb[idx].first>=i){
            pq.push(bomb[idx].second);
            idx--;
        }

        if(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
    }
 
    cout<<ans;
    return 0;
}