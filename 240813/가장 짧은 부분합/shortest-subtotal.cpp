#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

int main() {
    int n,s;
    cin>>n>>s;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = n;

    for(int i=0; i<n-1; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum>=s){
                ans = min(ans, j-i+1);
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}