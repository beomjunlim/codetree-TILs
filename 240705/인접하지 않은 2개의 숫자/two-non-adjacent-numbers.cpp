#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[101];
    int ans = 0;

    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n-2; i++){
        int num = arr[i];
        for(int j=i+2; j<n; j++){
            int sum = num + arr[j];
            ans = max(ans, sum);
        }
    }

    cout<<ans;
    return 0;
}