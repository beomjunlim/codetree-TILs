#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int min_dp[1001];
int max_dp[1001];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        max_dp[i] = min_dp[i] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(arr[j]<arr[i]){
                max_dp[i] = max(max_dp[i], max_dp[j] + 1);
            }
            else if(arr[j]>arr[i]){
                min_dp[i] = max(min_dp[i], min_dp[j] + 1);
            }
        }
    }

    int one = 0;
    int two = 0;
    int thr = 0;

    for(int i=0; i<n; i++){
        one = max(one, max_dp[i]);
        two = max(two, min_dp[i]);
    }

    for(int i=0; i<n; i++){
        int num = max_dp[i];
        
        for(int j=0; j<n; j++)
            min_dp[j] = 1;
        for(int j=i+1; j<n; j++){
            for(int k=i; k<=j; k++){
                if(arr[k]>arr[j])
                    min_dp[j] = max(min_dp[j], min_dp[k] + 1);
            }
        }

        for(int j=i; j<n; j++)
            thr = max(thr, num + min_dp[j] - 1);
    }

    int ans = max(one, max(two, thr));
    cout<<ans;
    return 0;
}