#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first==b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<int> A;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        A.push_back(a);
    }

    vector<pair<int,int>> B;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        B.push_back(make_pair(a,b));
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);

    int ans = 0;

    int a = 0;
    int b = 0;

    while(a<n&&b<m){
        int left = B[b].first;
        int right = B[b].second;

        int mid = A[a];

        if(left<=mid&&mid<=right){
            ans++;
            a++;
            b++;
        }
        else if(left>mid){
            a++;
        }
        else{
            b++;
        }
    }

    cout<<ans;
    return 0;
}