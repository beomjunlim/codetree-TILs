#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[21][21];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            int sum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            ans = max(ans, sum);
        }
    }

    cout<<ans;
    return 0;
}