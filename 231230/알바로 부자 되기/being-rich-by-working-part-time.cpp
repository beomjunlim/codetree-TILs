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
    vector<pair<int,int>> v;
    vector<int> pay;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(a,b));
        pay.push_back(c);
        dp[i] = c;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i].first>v[j].second)
                dp[i] = max(dp[i], dp[j] + pay[j]);
        }
    }

    sort(dp, dp+n);
    cout<<dp[n-1];

    return 0;
}