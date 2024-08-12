#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int>> num;
    for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        num.push_back(make_pair(x,y));
    }

    sort(num.begin(), num.end());

    int ans = 1;
    int start = num[0].first;
    int end = num[0].second;
    for(int i=0; i<n; i++){
        if(num[i].first<end){
            end = max(end, num[i].second);
        }
        else{
            ans++;
            end = num[i].second;
        }
    }

    cout<<ans;
    return 0;
}