#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

int n, start_x, start_y, end_x, end_y;
int max_num = 0;
int ans = 987654321;
char arr[21][21];
int coin[3];
vector<pair<int, pair<int,int>>> num;

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    return a.first < b.first;
}

void backtracking(int cnt){
    if(cnt==3){
        int sum = 0;
        sum = (abs(start_x - num[coin[0]].second.first) + abs(start_y - num[coin[0]].second.second));
        for(int i=1; i<3; i++){
            sum += (abs(num[coin[i-1]].second.first - num[coin[i]].second.first) + abs(num[coin[i-1]].second.second - num[coin[i]].second.second));
        }

        sum += (abs(num[coin[2]].second.first - end_x) + abs(num[coin[2]].second.second - end_y));
        ans = min(ans, sum);
        return;
    }

    for(int i=0; i<num.size(); i++){
        if(cnt!=0){
            if(num[coin[cnt-1]].first < num[i].first){
                coin[cnt] = i;
                backtracking(cnt+1);
            }
        }
        else{
            coin[cnt] = i;
            backtracking(cnt+1);
        }
        
    }
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            int number = arr[i][j] -'0';
            if(0<number&&number<9){
                num.push_back(make_pair(number, make_pair(i,j)));
            }
            if(arr[i][j]=='S'){
                start_x = i;
                start_y = j;
            }
            if(arr[i][j]=='E'){
                end_x = i;
                end_y = j;
            }
        }
    }

    sort(num.begin(), num.end(), cmp);

    backtracking(0);

    if(ans==987654321)
        ans = -1;
    cout<<ans;
    return 0;
}