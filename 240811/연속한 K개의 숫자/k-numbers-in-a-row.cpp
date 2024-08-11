#include <iostream>
#include <algorithm>
using namespace std;

bool visited[100001];
int sum[100001];

int main() {
    int n,k,b;
    cin>>n>>k>>b;

    for(int i=0; i<b; i++){
        int a;
        cin>>a;
        visited[a] = true;
    }

    for(int i=1; i<=n; i++){
        int num = 0;
        if(visited[i])
            num = 1;
        sum[i] = sum[i-1] + num;
    }

    int ans = n;
    for(int i=k; i<=n; i++){
        ans = min(ans, sum[i] - sum[i-k]);
    }

    cout<<ans;
    return 0;
}