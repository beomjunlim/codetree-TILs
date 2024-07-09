#include <iostream>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[101];

    int ans = -1;
    bool sw = false;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        arr[x]++;
        if(arr[x]>=k&&!sw){
            sw = true;
            ans = x;
        }
    }

    cout<<ans;
    return 0;
}