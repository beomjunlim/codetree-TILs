#include <iostream>
using namespace std;

int n;
int arr[9];
bool visited[9];

void backtracking(int cnt){
    if(cnt==n){
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
        cout<<'\n';
        return;
    }

    for(int i=n; i>=1; i--){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i;
            backtracking(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin>>n;

    backtracking(0);
    return 0;
}