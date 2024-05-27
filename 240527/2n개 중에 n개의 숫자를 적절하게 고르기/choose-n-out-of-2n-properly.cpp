#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int arr[21];
int sum = 0;
int ans;

void backtracking(int num, int idx, int cnt){
    if(num==n){
        int A = sum - cnt;
        int B = cnt;
        ans = min(ans, abs(A-B));
        return;
    }

    for(int i=idx; i<2*n; i++){
        backtracking(num+1, i+1, cnt + arr[i]);
    }
}
int main() {
    cin>>n;

    
    for(int i=0; i<2*n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    ans = sum;

    backtracking(0,0,0);

    cout<<ans<<'\n';
    return 0;
}