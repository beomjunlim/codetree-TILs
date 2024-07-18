#include <iostream>
using namespace std;

int main() {
    int n,k,b;
    cin>>n>>k>>b;

    bool arr[100001] = {false};
    for(int i=0; i<b; i++){
        int a;
        cin>>a;
        arr[a] = true;
    }

    int ans = n;
    for(int i=k; i<=n; i++){
        int cnt = 0;
        for(int j=0; j<k; j++){
            if(arr[i-j])
                cnt++;
        }
        ans = min(ans,cnt);
    }

    cout<<ans;
    return 0;
}