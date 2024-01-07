#include <iostream>
#include <climits>
using namespace std;

#define MAX 100000
int arr[MAX];
int ans[MAX];

int main() {
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
        if (i==0)
            ans[i] = arr[i];
        else
            ans[i] = arr[i] + ans[i-1];
    }

    int sum = INT_MIN;
    for(int i=n-1; i>k-2; i--){
        sum = max(sum, ans[i] - ans[i-k]);
    }

    cout<<sum;
    return 0;
}