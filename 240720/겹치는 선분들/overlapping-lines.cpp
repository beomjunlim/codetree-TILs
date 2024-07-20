#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> arr;
    vector<pair<int,int>> sum;

    int idx = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int a;
        char b;
        cin>>a>>b;
        if(b=='L'){
            arr.push_back(make_pair(idx-a, idx));
            idx = idx - a;
        }
        else{
            arr.push_back(make_pair(idx, idx+a));
            idx = idx + a;
        }
    }

    for(int i=0; i<n; i++){
        int x = arr[i].first;
        int y = arr[i].second;

        sum.push_back(make_pair(x,1));
        sum.push_back(make_pair(y,-1));
    }

    sort(sum.begin(), sum.end());

    int sum_val = 0;
    for(int i=0; i<2*n; i++){
        int x = sum[i].first;
        int y = sum[i].second;

        if(sum_val>=k){
            int prev_x = sum[i-1].first;
            ans += x - prev_x;
        }
        sum_val += y;
    }

    cout<<ans;
    return 0;
}