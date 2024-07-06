#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,char>a, pair<int,char>b){
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,char>> v;

    for(int i=0; i<n; i++){
        int x;
        char y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), cmp);

    int ans = 0;

    for(int i=0; i<v.size(); i++){
        int G = 0;
        int H = 0;
        for(int j=i; j<v.size(); j++){
            if(v[j].second=='G')
                G++;
            if(v[j].second=='H')
                H++;
            
            if(G==H)
                ans = max(ans, v[j].first - v[i].first);
        }
    }

    cout<<ans;
    return 0;
}