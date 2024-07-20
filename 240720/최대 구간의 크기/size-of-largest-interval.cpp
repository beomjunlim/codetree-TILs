#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int> b){
    if(a.first==b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    vector<pair<int,int>> point;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end(), cmp);

    int ans = 0;
    
    int start = arr[0].first;
    int end = arr[0].second;

    for(int i=1; i<n; i++){
        if(end < arr[i].second){
            if(end < arr[i].first){
                ans = max(ans, end - start);
                start = arr[i].first;
                end = arr[i].second;
            }
            else{
                end = arr[i].second;
            }
        }
    }

    ans = max(ans, end - start);
    cout<<ans;
    return 0;
}