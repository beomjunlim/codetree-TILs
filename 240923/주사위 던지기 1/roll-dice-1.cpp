#include <iostream>
using namespace std;

int n,m;
int ans[6];
bool visited[7];

void backtracking_a(int cnt){
    if(cnt==n){
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1; i<=6; i++){
        ans[cnt] = i;
        backtracking_a(cnt+1);
    }
}

void backtracking_b(int cnt, int num){
    if(cnt==n){
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=num; i<=6; i++){
        ans[cnt] = i;
        backtracking_b(cnt+1, i);
    }
}

void backtracking_c(int cnt){
    if(cnt==n){
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=1; i<=6; i++){
        if(!visited[i]){
            visited[i] = true;
            ans[cnt] = i;
            backtracking_c(cnt+1);
            visited[i] = false;
        }
    }
}

int main() {
    cin>>n>>m;

    if(m==1){
        backtracking_a(0);
    }
    else if(m==2){
        backtracking_b(0,1);
    }
    else if(m==3){
        backtracking_c(0);
    }
    return 0;
}