#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b){
    return a.second < b.second;
}

int main() {
    int n,a,b;
    cin>>n>>a>>b;

    vector<pair<char,int>> v;

    for(int i=0; i<n; i++){
        char a;
        int x;
        cin>>a>>x;
        v.push_back(make_pair(a,x));
    }

    sort(v.begin(), v.end(), cmp);
    int ans = 0;
    for(int i=a; i<=b; i++){
        int d1 = 1001;
        int d2 = 1001;

        for(int j=0; j<n; j++){
            if(v[j].first == 'S'){
                d1 = min(d1, abs(i-v[j].second));
            }

            if(v[j].first == 'N'){
                d2 = min(d2, abs(i-v[j].second));
            }
        }

        if(d1<=d2){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}