#include <iostream>
using namespace std;

#define MAX 1001

int arr[MAX];

int main() {
    int n;
    cin>>n;

    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;

    for(int i=4; i<=n; i++){
        arr[i] = (arr[i-2]+arr[i-3])%10007;
    }
    cout<<arr[n];
    return 0;
}