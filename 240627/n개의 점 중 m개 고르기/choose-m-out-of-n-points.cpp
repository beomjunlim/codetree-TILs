#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n,m;
double ans = 987654321;
vector<pair<int,int>> arr;
vector<pair<int,int>> sequence;

void backtracking(int num, int cnt){
    if(cnt==m){
        double max_num = 0;
        for(int i=0; i<cnt; i++){
            for(int j=i+1; j<cnt; j++){
                int x = abs(sequence[i].first - sequence[j].first);
                int y = abs(sequence[i].second - sequence[j].second);
                double number = x*x + y*y;
                max_num = max(max_num, number);
            }
        }

        ans = min(ans, max_num);
        return;
    }

    for(int i=num; i<n; i++){
        int x = arr[i].first;
        int y = arr[i].second;
        sequence.push_back(make_pair(x,y));
        backtracking(i+1, cnt+1);
        sequence.pop_back();
    }
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr.push_back(make_pair(a,b));
    }

    backtracking(0,0);
    cout<<ans;
    return 0;
}