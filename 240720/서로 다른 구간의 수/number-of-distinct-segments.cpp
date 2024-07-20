#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<long long, long long> a, pair<long long, long long> b){
    if(a.first==b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<long long, long long>> arr;
    for(int i=0; i<n; i++){
        long long a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;
    long long start = arr[0].first;
    long long end = arr[0].second;
    for(int i=1; i<n; i++){
        if(end<arr[i].first){
            ans++;
            start = arr[i].first;
            end = arr[i].second;
        }
        else{
            end = max(end, arr[i].second);
        }
    }
    cout<<ans + 1;
    return 0;
}