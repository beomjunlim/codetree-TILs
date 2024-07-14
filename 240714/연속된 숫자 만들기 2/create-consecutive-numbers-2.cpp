#include <iostream>
#include <algorithm>
using namespace std;

long long arr[3];

int main() {
    for(int i=0; i<3; i++){
        cin>>arr[i];
    }

    sort(arr, arr+3);

    if(arr[0]+1==arr[1]&&arr[1]+1==arr[2])
        cout<<0;
    else if(arr[0]+2==arr[1]||arr[1]+2==arr[2])
        cout<<1;
    else
        cout<<2;
    return 0;
}