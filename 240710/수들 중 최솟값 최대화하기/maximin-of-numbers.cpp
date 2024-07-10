#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[11][11];
bool visited[11];
int low[11];
int ans = 0;

void backtracking(int cnt){
    if(cnt==n){
        int num = 987654321;
        for(int i=0; i<n; i++){
            num = min(num, arr[low[i]][i]);
        }
        ans = max(ans, num);
    }

    for(int i=0; i<n; i++){
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

    backtracking(0);
    cout<<ans;
    return 0;
}