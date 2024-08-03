#include <iostream>
#include <algorithm>
using namespace std;

string s;
int arr[201];
int number[4] = {1,2,3,4};
int num = 0;
int ans = 0;

void backtracking(int cnt){
    if(cnt==num){
        int temp = arr[0];
        int idx = 1;
        int num_idx = 1;
        while(idx<s.length()){
            if(s[idx]=='+'){
                temp += arr[num_idx];
                idx += 2;
            }
            else if(s[idx]=='-'){
                temp -= arr[num_idx];
            }
            else if(s[idx]=='*'){
                temp *= arr[num_idx];
            }
            num_idx++;
            idx += 2;
        }
        ans = max(ans, temp);
        return;
    }

    for(int i=0; i<4; i++){
        arr[cnt] = number[i];
        backtracking(cnt+1);
    }
}
int main() {
    cin>>s;

    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&&s[i]<='f')
            num++;
    }

    backtracking(0);
    cout<<ans;

    return 0;
}