#include <iostream>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int arr[101] = {0};

    int ans = -1;
    int idx = 0;
    bool sw = false;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        idx = x;
        arr[x]++;
        if(arr[x]>=k&&!sw){
            sw = true;
            ans = x;
        }
    }



    cout<<ans;
    return 0;
}