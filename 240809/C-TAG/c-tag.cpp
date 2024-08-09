#include <iostream>
#include <unordered_set>
using namespace std;

int n,m;
string A[501];
string B[501];
int ans[3];
int count = 0;

void backtracking(int cnt, int num){
    if(cnt==3){
        unordered_set<string> all;

        unordered_set<string> a;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<3; j++){
                temp += A[i][ans[j]];
            }
            all.insert(temp);
            a.insert(temp);
        }

        unordered_set<string> b;
        for(int i=0; i<n; i++){
            string temp = "";
            for(int j=0; j<3; j++){
                temp += B[i][ans[j]];
            }
            all.insert(temp);
            b.insert(temp);
        }

        if(a.size() + b.size() == all.size())
            count++;
        return;
    }

    for(int i=num; i<m; i++){
        ans[cnt] = i;
        backtracking(cnt+1, i+1);
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++)
        cin>>A[i];
    
    for(int i=0; i<n; i++)
        cin>>B[i];
    
    backtracking(0,0);
    cout<<count;

    return 0;
}