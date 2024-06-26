#include <iostream>
#include <vector>
using namespace std;

int n;
int answer = 0;
vector<int> ans;

bool check(){
    for(int i=0; i<ans.size(); i+=ans[i]){
        int num = ans[i];
        for(int j=0; j<num; j++){
            if(num!=ans[i+j])
                return false;
        }
    }
    return true;
}

void backtracking(int cnt){
    if(cnt==n){
        if(check()){
            answer++;
        }
        return;
    }

    for(int i=1; i<=4; i++){
        ans.push_back(i);
        backtracking(cnt+1);
        ans.pop_back();
    }
}

int main() {
    cin>>n;
    backtracking(0);
    cout<<answer;
    return 0;
}