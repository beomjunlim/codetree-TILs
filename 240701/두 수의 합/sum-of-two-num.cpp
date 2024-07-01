#include <iostream>
#include <unordered_map>
using namespace std;

int n,m;
unordered_map<int,int> maps;
int ans[2];
int answer = 0;

void backtracking(int num, int cnt){
    if(cnt==2){
        int sum = 0;
        for(int i=0; i<2; i++){
            sum += ans[i];
        }

        if(sum==m)
            answer++;
        return;
    }

    for(int i=num; i<n; i++){
        ans[cnt] = maps[i];
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        maps[i] = a;
    }

    backtracking(0,0);
    cout<<answer;
    return 0;
}