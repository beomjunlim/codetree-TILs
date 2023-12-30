#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000

int arr[MAX];
int dp[MAX];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }


    sort(dp, dp+n);
    cout<<dp[n-1];
    return 0;
}