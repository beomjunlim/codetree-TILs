#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first + a.second < b.first + b.second; 
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(), v.end(), cmp);
    int ans = 0;

    for(int i=0; i<n; i++){
        int sum = m;
        sum -= v[i].first/2;
        sum -= v[i].second;
        int cnt = 1;
        for(int j=0; j<n; j++){
            if(i!=j){
                int num = v[j].first + v[j].second;
                if(sum - num >=0){
                    sum -= num;
                    cnt++;
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout<<ans;
    return 0;
}