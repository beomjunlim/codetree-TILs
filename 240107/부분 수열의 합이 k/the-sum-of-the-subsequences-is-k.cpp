#include <iostream>
using namespace std;

#define MAX 1000

int arr[MAX+1];
int ans[MAX+1];

int main() {
    int n,k;
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    ans[0] = 0;

    for(int i=1; i<=n; i++){
        ans[i] = ans[i-1] + arr[i];
    }

    int sum = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            if(ans[j] - ans[i-1] == k)
                sum++;
        }
    }
    cout<<sum;
    return 0;
}