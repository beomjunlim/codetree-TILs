#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[3];

    for(int i=0; i<3; i++)
        cin>>arr[i];

    int diff1 = arr[1] - arr[0];
    int diff2 = arr[2] - arr[1];

    int cnt = max(diff1, diff2) - 1;

    cout << cnt;
    return 0;
}