#include <iostream>
#include <algorithm>
using namespace std;

string a,b;
int dp[1001][1001];

int main() {
    cin>>a>>b;

    a = " " + a;
    b = " " + b;

    int A = a.length();
    int B = b.length();

    if(a[1]==b[1])
        dp[1][1] = 1;
    else
        dp[1][1] = 0;
    
    for(int i=1; i<A; i++){
        if(a[i]==b[1])
            dp[i][1] = 1;
        else
            dp[i][1] = 0;
    }

    for(int i=1; i<B; i++){
        if(b[i]==a[1])
            dp[1][i] = 1;
        else
            dp[1][i] = 0;
    }

    for(int i=2; i<A; i++){
        for(int j=2; j<B; j++){
            if(a[i]==b[j])
                dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int ans = 0;

    for(int i=1; i<A; i++){
        for(int j=1; j<B; j++){
            ans = max(ans, dp[i][j]);        
        }
    }
    
    cout<<ans;
    return 0;
}