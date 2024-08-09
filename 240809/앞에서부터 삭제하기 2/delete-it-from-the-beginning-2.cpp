#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int main() {
    int n;
    cin>>n;

    double ans = 0;
    priority_queue<pair<int,int>> pq;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        dp[i] = dp[i-1] + arr[i];
        pq.push(make_pair(-arr[i],i));
    }

    for(int i=1; i<=n-2; i++){
        double sum = dp[n] - dp[i];
        int num = pq.top().first;
        int idx = pq.top().second;
        while(idx<=i){
            pq.pop();
            num = pq.top().first;
            idx = pq.top().second;
        }

        sum += num;
        int cnt = n - i - 1;
        ans = max(ans, (double)sum/cnt);
    }

    cout<<fixed<<setprecision(2);
    cout<<ans;
    return 0;
}