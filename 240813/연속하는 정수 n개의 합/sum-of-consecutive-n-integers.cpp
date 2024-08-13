#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
long long sum[100001];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    int ans = 0;
    int start = 0;
    int end = 1;
    int num;
    while(start<end){
        num =  sum[end] - sum[start];
        if(num==m){
            ans++;
            end++;
        }
        else if(num<m){
            end++;
        }
        else if(num>m){
            start++;
        }
    }

    cout<<ans;
    return 0;
}