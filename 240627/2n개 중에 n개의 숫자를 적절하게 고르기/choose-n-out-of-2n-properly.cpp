#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int ans = 987654321;
int total = 0;
int arr[21];

void backtracking(int num, int cnt, int sum){
    if(cnt==n){
        int A = total - sum;
        int B = sum;
        ans = min(ans, abs(A-B));
        return;
    }

    for(int i=num; i<2*n; i++){
        backtracking(i+1, cnt+1, sum - arr[i]);
    }
}

int main() {
    cin>>n;

    for(int i=0; i<2*n; i++){
        cin>>arr[i];
        total += arr[i];
    }

    backtracking(0,0, total);
    cout<<ans;
    return 0;
}