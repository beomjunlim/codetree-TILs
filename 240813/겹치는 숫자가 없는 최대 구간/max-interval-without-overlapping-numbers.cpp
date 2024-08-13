#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int Count[100001];

int main() {
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int ans = 0;
    int j = 1;
    for(int i=1; i<=n; i++){
        while(j<n){
            if(Count[arr[j]]==1){
                ans = max(ans, j-i+1);
                break;
            }
            Count[arr[j]] = 1;
            j++;
            if(j==n)
                ans = max(ans, j-i+1);
        }
    }
    
    cout<<ans;
    return 0;
}