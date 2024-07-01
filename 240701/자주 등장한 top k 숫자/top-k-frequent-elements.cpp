#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int n,k;
unordered_map<int, int> maps;
vector<pair<int, int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        maps[a]++;
    }

    for(auto it : maps){
        v.push_back({it.first, it.second});
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<k; i++){
        cout<<v[i].first<<" ";
    }
    return 0;
}