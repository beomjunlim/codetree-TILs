#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX+1];
bool dp[MAX+1][100000];

int main() {
    int n;
    int sum = 0;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    dp[0][0] = true;

    for(int i=1; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(j>=arr[i] && dp[i-1][j-arr[i]])
                dp[i][j] = true;
            if(dp[i-1][j])
                dp[i][j] = true;
        }
    }

    if(sum%2==0&&dp[n][sum/2])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}