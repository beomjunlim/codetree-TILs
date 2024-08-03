#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string s;
unordered_map<char,int> alphabet;
char arr[6];
int number[4] = {1,2,3,4};
int num = 0;
int ans = -(int)1e9;

void backtracking(int cnt){
    if(cnt==num){
        int idx = 0;
        int temp = alphabet[s[idx]];
        idx++;

        while(idx<s.length()){
            if(s[idx]=='+'){
                temp += alphabet[s[idx+1]];
            }
            else if(s[idx]=='-'){
                temp -= alphabet[s[idx+1]];
            }
            else if(s[idx]=='*'){
                temp *= alphabet[s[idx+1]];
            }
            idx += 2;
        }
        ans = max(ans, temp);
        return;
    }

    for(int i=1; i<=4; i++){
        alphabet[arr[cnt]] = i;
        backtracking(cnt+1);
    }
}

int main() {
    cin>>s;

    unordered_set<char> sets;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='a'&&s[i]<='f'&&sets.find(s[i])==sets.end()){
            sets.insert(s[i]);
            arr[num] = s[i];
            num++;
        }
    }

    backtracking(0);
    cout<<ans;

    return 0;
}