#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string A[101][2];
int ans[26];
string arr[101];

void backtracking(int idx,int cnt){
    if(cnt==n){
        int temp[26] = {0};
        for(int i=0; i<n; i++){
            string str = arr[i];
            for(int j=0; j<str.length(); j++){
                int num = str[j] - 'a';
                temp[num]++;
            }
        }

        for(int i=0; i<26; i++){
            ans[i] = max(ans[i], temp[i]);
        }
        return;
    }

    arr[idx] = A[idx][0];
    backtracking(idx+1, cnt+1);
    arr[idx] = A[idx][1];
    backtracking(idx+1, cnt+1);
}
int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>A[i][0]>>A[i][1];
    }

    backtracking(0,0);

    for(int i=0; i<26; i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}