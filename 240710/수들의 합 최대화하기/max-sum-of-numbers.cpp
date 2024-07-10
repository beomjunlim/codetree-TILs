#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int arr[11][11];
bool low[11];
bool col[11];
int answer[11];

void backtracking(int cnt){
    if(cnt==n){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i][answer[i]];
        }
        ans = max(ans, sum);
        return;
    }

    for(int i=0; i<n; i++){
        if(!low[i]){
            low[i] = true;
            answer[cnt] = i;
            backtracking(cnt+1);
            low[i] = false;
        }
    }
}
int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    backtracking(0);
    cout<<ans;
    return 0;
}