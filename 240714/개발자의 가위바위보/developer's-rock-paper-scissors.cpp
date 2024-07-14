#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> v;
    int ans = 0;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    int rock;
    int scissors;
    int paper;

    int cnt;
    // rock 1 scissors 2 paper 3
    rock = 1;
    scissors = 2;
    paper = 3;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);

    // rock 1 scissors 3 paper 2
    rock = 1;
    scissors = 2;
    paper = 3;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);
    // rock 2 scissors 1 paper 3
    rock = 2;
    scissors = 1;
    paper = 3;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);
    // rock 2 scissors 3 paper 1
    rock = 2;
    scissors = 3;
    paper = 1;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);
    // rock 3 scissors 1 paper 2
    rock = 3;
    scissors = 1;
    paper = 2;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);
    // rock 3 scissors 2 paper 1
    rock = 3;
    scissors = 2;
    paper = 1;
    cnt = 0;
    for(int i=0; i<n; i++){
        if(v[i].first==rock&&v[i].second==scissors)
            cnt++;
        else if(v[i].first==scissors&&v[i].second==paper)
            cnt++;
        else if(v[i].first==paper&&v[i].second==rock)
            cnt++;
    }

    ans = max(ans, cnt);
    cout<<ans;
    return 0;
}