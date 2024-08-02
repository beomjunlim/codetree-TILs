#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int ans = (int)1e9;
vector<pair<int,int>> lines;
vector<pair<int,int>> selected;
bool Possible(){
    int num1[11], num2[11];

    for(int i=0; i<n; i++)
        num1[i] = num2[i] = i;
    
    for(int i=0; i<lines.size(); i++){
        int idx = lines[i].second;
        swap(num1[idx], num1[idx+1]);
    }

    for(int i=0; i<selected.size(); i++){
        int idx = selected[i].second;
        swap(num2[idx], num2[idx+1]);
    }

    for(int i=0; i<n; i++){
        if(num1[i]!=num2[i])
            return false;
    }
    return true;
}

void backtracking(int cnt){
    if(cnt==m){ // 모든 경우를 본 경우
        if(Possible())
            ans = min(ans, (int)selected.size());
        return;
    }

    selected.push_back(lines[cnt]);
    backtracking(cnt+1); // 해당 사다리 넣었을 경우
    selected.pop_back();
    backtracking(cnt+1); // 해당 사다리 넣지 않았을 경우
}

int main() {
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        lines.push_back(make_pair(b,a-1));
    }

    sort(lines.begin(), lines.end());

    backtracking(0);
    cout<<ans;
    return 0;
}