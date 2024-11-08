#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000000

int n,m;
int arr[100001];

bool Possible(long long time){
    long long cnt = 0;
    for(int i=0; i<m; i++){
        cnt += time/arr[i];

        if(cnt>=n)
            return true;
    }
    return false;
}

int main() {
    
    cin>>n>>m;

    for(int i=0; i<m; i++){
        cin>>arr[i];
    }

    sort(arr, arr+m);

    long long left = 1;
    long long right = (long long)n*arr[m-1];
    long long ans = right;

    while(left<=right){
        long long mid = (left + right) / 2;

        if(Possible(mid)){
            ans = min(ans, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    cout<<ans;
    return 0;
}