#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int arr[101];

    for(int i=0; i<n; i++)
        cin>>arr[i];

    int idx = 0;

    for(int i=1; i<n; i++){
        if(arr[i-1]>arr[i])
            idx = i;
    }

    cout<<idx;
    return 0;
}