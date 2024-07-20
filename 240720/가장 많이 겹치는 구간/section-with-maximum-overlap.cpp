#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[100001] = {0};
    int max_num = 0;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[a] = 1;
        arr[b] = -1;
        max_num = max(max_num,b);
    }

    int ans = 0;
    int sum = 0;
    
    for(int i=1; i<=max_num; i++){
        sum+=arr[i];
        ans = max(ans, sum);
    }

    cout<<ans;

    return 0;
}