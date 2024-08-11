#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> arr;

bool cmp(pair<int,int>a, pair<int,int>b){
    return a.first < b.first;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr.push_back(make_pair(x,y));
    }

    sort(arr.begin(), arr.end(), cmp);

    int ans = n;
    int start = arr[0].second;
    
    for(int i=1; i<n; i++){
        if(start>arr[i].second){
            ans-=2;
        }
        else{
            start = arr[i].second;
        }
    }

    cout<<ans;
    return 0;
}