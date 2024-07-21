#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int>a, pair<int,int> b){
    return a.first > b.first;
}

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> arr;
    int m = 0;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        arr.push_back(make_pair(y,x));
        m += x;
    }

    sort(arr.begin(), arr.end());
    
    int start = 0;
    int end = arr.size()-1;

    int a = arr[start].first;
    int start_idx = arr[start].second;
    int b = arr[end].first;
    int end_idx = arr[end].second;
    
    int ans = 0;

    while(start<=end){
        ans = max(ans, a+b);
        start_idx--;
        end_idx--;

        if(start>end)
            break;

        if(start_idx==0){
            start++;
            a = arr[start].first;
            start_idx = arr[start].second;
        }

        if(end_idx==0){
            end--;
            b = arr[end].first;
            end_idx = arr[end].second;
        }
    }

    cout<<ans;
    return 0;
}