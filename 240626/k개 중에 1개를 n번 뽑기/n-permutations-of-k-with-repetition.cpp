#include <iostream>
#include <vector>
using namespace std;

int k,n;
vector<int> ans;

void backtracking(int num, int cnt){
    if(cnt==n){
        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }
        cout<<'\n';
        return;
    }

    for(int i=num; i<=k; i++){
        ans.push_back(i);
        backtracking(num, cnt+1);
        ans.pop_back();
    }
}

int main() {
    cin>>k>>n;
    backtracking(1,0);
    return 0;
}