#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];

int main() {
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        for(int j=a; j<=b; j++)
            arr[j]++;
    }    

    int ans = 0;
    for(int i=0; i<101; i++)  
        ans = max(ans, arr[i]);
    
    cout<<ans;
    return 0;
}