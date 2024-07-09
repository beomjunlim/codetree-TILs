#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;

bool visited[101] = {false};

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
    return a.first < b.first;
}

int main() {
    int n,k,p,t;
    cin>>n>>k>>p>>t;

    vector<pair<int,pair<int,int>>> v;
    int arr[101]={0};

    arr[p] = k;
    visited[p] = true;

    for(int i=0; i<t; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back(make_pair(a,make_pair(b,c)));
    }

    sort(v.begin(), v.end(), cmp);
    
    for(int i=0; i<t; i++){
        int a = v[i].second.first;
        int b = v[i].second.second;

        if(arr[a]>0&&arr[b]==0){
            arr[a]--;
            arr[b] = k;
            visited[b] = true;
        }
        else if(arr[a]==0&&arr[b]>0){
            arr[b]--;
            arr[a] = k;
            visited[a] = true;
        }
        else if(arr[a]>0&&arr[b]>0){
            arr[a]--;
            arr[b]--;
        }

    }

    for(int i=1; i<=n; i++){
        if(visited[i])
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}