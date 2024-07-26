#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;

    int arr[101] ={0};
    int ans = 0;

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        for(int j=a; j<=b; j++){
            arr[j]++;
            ans = max(ans,arr[j]);
        }
    }

    cout<<ans;
    return 0;
}