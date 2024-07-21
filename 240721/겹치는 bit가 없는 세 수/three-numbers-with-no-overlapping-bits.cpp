#include <iostream>
using namespace std;

int n;
int arr[501];
int ans[3];
int answer = 0;

void backtracking(int num, int cnt){
    if(cnt==3){
        int a = ans[0];
        int b = ans[1];
        int c = ans[2];

        if((a&b)==0&&(a&c)==0&&(b&c)==0){
            answer = max(answer, a+b+c);
        }
        return;
    }

    for(int i=num; i<n; i++){
        ans[cnt] = arr[i];
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    backtracking(0,0);
    cout<<answer;
    return 0;
}