#include <iostream>
using namespace std;

#define MAX 1000000000

int arr[100001];

int main() {
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>arr[i];
    }

    long long left = 1;
    long long right = n*MAX;
    long long ans = right;

    while(left<=right){
        long long mid = (left + right) / 2;

        int cnt = 0;
        for(int i=0; i<m; i++){
            cnt += mid/arr[i];
        }

        if(cnt>=n){
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout<<ans;
    return 0;
}