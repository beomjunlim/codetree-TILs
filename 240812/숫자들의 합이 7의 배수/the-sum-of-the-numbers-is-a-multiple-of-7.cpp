#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[50001];
long long sum[50001];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = (sum[i-1] + arr[i])%7;
    }

    map<int,int> ans;
    ans[0] = 0;
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        if(ans.find(sum[i])!=ans.end()){
            answer = max(answer, i - ans[sum[i]]);
        }
        else{
            ans[sum[i]] = i;
        }
    }

    cout<<answer;
    return 0;
}