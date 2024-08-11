#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool visited[100001];
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

    int ans = 0;
    int start = arr[0].second;
    int idx = 0;

    for(int i=1; i<n; i++){
        if(start>arr[i].second){
            visited[i] = true;
            visited[idx] = true;
        }
        else{
            start = arr[i].second;
            idx = i;
        }
    }

    for(int i=0; i<n; i++){
        if(!visited[i])
            ans++;
    }
    
    cout<<ans;
    return 0;
}