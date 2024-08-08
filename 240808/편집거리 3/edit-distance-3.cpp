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
        dp[1][1] = 0;
    else
        dp[1][1] = 2;
    
    for(int i=2; i<A; i++){
        if(a[i]==b[1])
            dp[1][i] = i - 1;
        else
            dp[1][i] = dp[1][i-1] + 1;
    }

    for(int i=2; i<B; i++){
        if(b[i]==a[1])
            dp[i][1] = i - 1;
        else
            dp[i][1] = dp[i-1][1] + 1;
    }

    for(int i=2; i<B; i++){
        for(int j=2; j<A; j++){
            if(b[i]==a[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j], dp[i][j-1])) + 1;
        }
    }

    cout<<dp[B-1][A-1];
    return 0;
}