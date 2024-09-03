#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> arr;
int dp[101];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        dp[i] = 1;
    }    

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i].second > arr[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = n + 1;
    for(int i=0; i<n; i++){
        int num = n - dp[i];
        ans = min(ans, num);
    }

    cout<<ans;
    return 0;
}