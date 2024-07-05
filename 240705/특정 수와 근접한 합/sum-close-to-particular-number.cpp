#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n,s;
int ans = 987654321;
int arr[101];
vector<int> v;

void backtracking(int a, int cnt, int sum){
    if(cnt==2){
        int num = sum;
        for(int i=0; i<cnt; i++){
            num -= v[i];
        }

        ans = min(ans, abs(num - s));
        return;
    }

    for(int i=a; i<n; i++){
        v.push_back(arr[i]);
        backtracking(i+1,cnt+1,sum);
        v.pop_back();
    }
}

int main() {
    int sum = 0;
    cin>>n>>s;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum += arr[i];
    }

    backtracking(0,0,sum);
    cout<<ans;
    return 0;
}