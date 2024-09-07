#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = 0;
int arr[50001];
int start[3];

int calculate(int idx){
    int sum = 0;
    for(int i=start[idx]; i<start[idx]+m; i++){
        sum+= arr[i];
    }
    return sum;
}

void myFunction(int idx, int cnt){
    if(cnt==3){
        int sum = 0;
        for(int i=0; i<3; i++){
            sum += calculate(i);
        }
        ans = max(ans, sum);
        return;
    }

    for(int i=idx; i<=n-m+1; i++){
        start[cnt] = i;
        myFunction(i+m,cnt+1);
    }
}

int main() {
    cin>>n;
    
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    cin>>m;

    myFunction(1,0);
    cout<<ans;
    return 0;
}