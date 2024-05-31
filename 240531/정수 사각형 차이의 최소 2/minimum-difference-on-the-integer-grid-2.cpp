#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int arr[100][100];
int dp[100][100];
int ans = INT_MAX;

void Initialize(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = INT_MAX;
        }
    }

    dp[0][0] = arr[0][0];

    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], arr[i][0]);
    }

    for(int j=1; j<n; j++){
        dp[0][j] = max(dp[0][j-1], arr[0][j]);
    }
}

int Solve(int lower_bound){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]<lower_bound)
                arr[i][j] = INT_MAX;
        }
    }

    Initialize();

    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            dp[i][j] = max(min(dp[i-1][j], dp[i][j-1]), arr[i][j]);
        }
    }
    return dp[n-1][n-1];
}


int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=100; i++){
        int upper_bound = Solve(i);

        if(upper_bound == INT_MAX)
            continue;
        ans = min(ans, upper_bound - i);
    }

    cout<<ans;
    return 0;
}