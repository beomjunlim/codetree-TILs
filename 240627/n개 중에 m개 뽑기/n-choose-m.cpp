#include <iostream>
using namespace std;

int n,m;
int ans[11];

void backtracking(int num, int cnt){
    if(cnt==m){
        for(int i=0; i<cnt; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=num; i<=n; i++){
        ans[cnt] = i;
        backtracking(i+1, cnt+1);
    }


}

int main() {
    cin>>n>>m;
    backtracking(1, 0);
    return 0;
}