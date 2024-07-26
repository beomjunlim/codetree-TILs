#include <iostream>
#include <algorithm>
using namespace std;

int arr[201];

int main() {
    int n;
    cin>>n;
    int last = 0;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        a += 100;
        b += 100;

        for(int j=a; j<b; j++){
            arr[j]++;
        }
        last = max(last, b);
    }

    int ans = 0;
    
    for(int i=0; i<last; i++){
        ans = max(ans, arr[i]);
    }

    cout<<ans;
    return 0;
}