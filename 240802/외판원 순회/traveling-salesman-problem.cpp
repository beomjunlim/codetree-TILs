#include <iostream>
#include <algorithm>
using namespace std;

int n;
int answer = (int)1e9;
int arr[11][11];
int ans[11];
bool visited[11];

void backtracking(int cnt){
    if(cnt==n-1){
        bool sw = true;
        if(arr[1][ans[0]]==0){
            sw = false;
        }
        int num = arr[1][ans[0]];

        for(int i=1; i<n-1; i++){
            if(arr[ans[i-1]][ans[i]]==0){
                sw = false;
                break;
            }
            num += arr[ans[i-1]][ans[i]];
        }
        num += arr[ans[n-2]][1];

        if(sw)
            answer = min(answer, num);
    }

    for(int i=2; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            ans[cnt] = i;
            backtracking(cnt+1);
            visited[i] = false;
        }
    }
}
int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }
    
    backtracking(0);
    cout<<answer;
    return 0;
}