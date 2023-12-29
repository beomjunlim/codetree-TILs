#include <iostream>
using namespace std;

#define MAX 1001

int arr[MAX];

int main() {
    int n;
    cin>>n;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for(int i=4; i<=n; i++){
        arr[i] = (arr[i-1] + arr[i-2])%10007;
    }
    cout<<arr[n];
    return 0;
}