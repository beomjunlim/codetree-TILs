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

    vector<pair<int,int>> v;

    for(int i=0; i<n; i++){
        int s,t;
        cin>>s>>t;
        v.push_back(make_pair(t,s));
    }

    sort(v.begin(), v.end(), cmp);

    int score = 0;
    int time = 0;
    for(int i=0; i<n; i++){
        if(time<v[i].first){
            time = v[i].first;
            score += v[i].second;
        }
    }

    cout<<score<<'\n';
    return 0;
}