#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int ans = 987654321;
char arr[20][20];
bool visited[10];
vector<int> sequence;
pair<int,int> num[10];
pair<int,int> start;
pair<int,int> Myend;

void backtracking(int idx, int last){
    if(idx==3){
        int dis = 0;
        int x = start.first;
        int y = start.second;
        for(int i=0; i<3; i++){
            // cout<<num[sequence[i]].first<<" "<<num[sequence[i]].second<<'\n';
            int nx = num[sequence[i]].first;
            int ny = num[sequence[i]].second;
            dis += (abs(x-nx) + abs(y-ny));
            x = nx;
            y = ny;
        }
        dis += (abs(x-Myend.first) + abs(y-Myend.second));
        ans = min(ans, dis);
        return;
    }

    for(int i=1; i<10; i++){
        if(i>last&&visited[i]){
            sequence.push_back(i);
            backtracking(idx+1, i);
            sequence.pop_back();
        }
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]-'0'>0&&arr[i][j]-'0'<10){
                visited[arr[i][j]-'0'] = true;
                num[arr[i][j]-'0'].first = i;
                num[arr[i][j]-'0'].second = j;
            }

            if(arr[i][j]=='S'){
                start.first = i;
                start.second = j;
            }

            if(arr[i][j]=='E'){
                Myend.first = i;
                Myend.second = j;
            }
        }
    }

    backtracking(0,0);
    if(ans==987654321)
        ans = -1;
    cout<<ans<<'\n';
    return 0;
}