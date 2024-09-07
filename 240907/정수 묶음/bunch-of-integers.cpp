#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[50001];
int sum[50001];
int start[3];

void myFunction(int idx, int cnt){
    if(cnt==3){
        int temp = 0;
        for(int i=0; i<3; i++){
            temp += sum[start[i]+m-1] - sum[start[i]-1];
        }
        ans = max(ans, temp);
        return;
    }

    for(int i=idx; i<=n-m+1; i++){
        start[cnt] = i;
        myFunction(i+m,cnt+1);
    }
}

int main() {
    cin>>n;
    
    sum[0] = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        sum[i] = arr[i] + sum[i-1];
    }

    cin>>m;

    myFunction(1,0);
    cout<<ans;
    return 0;
}