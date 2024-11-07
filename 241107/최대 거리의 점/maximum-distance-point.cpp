#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;

    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    int left = 1;
    int right = 1000000000;
    int ans = 0;

    while(left<=right){
        int mid = (left + right)/2;

        bool sw = false;
        int cnt = 1;
        int last_idx = 0;
        for(int i=1; i<n; i++){
            if(v[i] - v[last_idx]>=mid){
                cnt++;
                last_idx = i;
            }
        }

        if(cnt>=m)
            sw = true;
    
        if(sw){
            left = mid + 1;
            ans = max(ans, mid);
        }
        else{
            right = mid - 1;
        }
    }

    

    cout<<ans;
    return 0;
}