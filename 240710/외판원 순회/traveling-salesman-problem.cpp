#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 987654321;
int arr[11][11];
bool visited[11];
int low[11];

void backtracking(int cnt){
    if(cnt==n){
        int sum = 0;
        int idx = low[0];
        for(int i=1; i<n; i++){
            if(arr[idx][low[i]]==0)
                return;
            sum += arr[idx][low[i]];
            idx = low[i];
        }
        
        sum += arr[idx][0];
        ans = min(ans, sum);
        return;
    }

    for(int i=1; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            low[cnt] = i;
            backtracking(cnt+1);
            visited[i] = false;
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
    low[0] = 0;
    backtracking(1);
    cout<<ans;
    return 0;
}