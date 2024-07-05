#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    int arr[101];
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int ans = 987654321;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i!=j){
                sum += arr[j]*abs(i-j);
            }
        }
        ans = min(ans, sum);
    }

    cout<<ans;
    return 0;
}