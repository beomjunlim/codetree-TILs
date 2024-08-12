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
    
    int start = num[0].first;
    int end = num[0].second;
    int ans = 0;

    for(int i=1; i<n; i++){
        if(end<num[i].first){
            ans += (end - start);
            start = num[i].first;
            end = num[i].second;
        }
        else{
            end = max(end, num[i].second);
        }
    }

    ans += (end - start);
    cout<<ans;
    return 0;
}