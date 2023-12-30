#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000

int dp[MAX];

bool compare(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int main() {
    
    int n;
    vector<pair<int,int>> v;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    sort(v.begin(), v.end(), compare);
    dp[0] = 1;

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i].first>v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);     
        }
    }

    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}