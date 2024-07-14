#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    int A = a.second - a.first;
    int B = b.second - b.first;

    return A > B;
}
int main() {
    int n;
    cin>>n;

    char arr[1001];
    vector<pair<int,int>> v;

    int idx = 0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]=='1'&&idx!=i){
            v.push_back(make_pair(idx,i));
            idx = i;
        }
    }

    sort(v.begin(), v.end(), cmp);
    int A = v[0].first;
    int B = v[0].second;
    int num = (A+B)/2;
    arr[num] = '1';

    idx = 0;
    int ans = n;
    for(int i=0; i<n; i++){
        if(arr[i]=='1'&&idx!=i){
            int num = i - idx;
            idx = i;
            ans = min(ans,num);
        }
    }

    cout<<ans;
    return 0;
}