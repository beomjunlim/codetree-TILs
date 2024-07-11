#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int idx = 0;
    int arr[100001];
    while(n!=1){
        arr[idx] = n%2;
        n /= 2;
        idx++;
    }
    arr[idx] = n;

    for(int i=idx; i>=0; i--)
        cout<<arr[i];
    return 0;
}