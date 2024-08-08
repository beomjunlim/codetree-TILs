#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

bool cmp(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main() {
    cin>>n>>k;

    unordered_map<int,int> num;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        num[a]++;
    }

    vector<pair<int,int>> ans;

    for(auto it : num){
        ans.push_back(make_pair(it.first, it.second));
    }

    sort(ans.begin(), ans.end(), cmp);

    for(int i=0; i<k; i++){
        cout<<ans[i].first<<" ";
    }

    return 0;
}