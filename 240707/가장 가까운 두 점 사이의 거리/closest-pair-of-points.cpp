#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;
long long ans = 9876543210000;
int X[101];
int Y[101];
vector<pair<int,int>> v;

void backtracking(int num, int cnt){
    if(cnt==2){
        int x1 = v[0].first;
        int y1 = v[0].second;
        int x2 = v[1].first;
        int y2 = v[1].second;

        long long sum = pow(abs(x1-x2),2) + pow(abs(y1-y2),2);
        ans = min(ans, sum);
    }

    for(int i=num; i<n; i++){
        v.push_back(make_pair(X[i],Y[i]));
        backtracking(i+1, cnt+1);
        v.pop_back();
    }
}
int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>X[i]>>Y[i];
    }

    backtracking(0,0);
    cout<<ans;
    return 0;
}