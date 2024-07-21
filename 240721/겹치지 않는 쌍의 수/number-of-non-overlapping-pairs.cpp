#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[5001];

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        int m;
        cin>>m;
        for(int j=0; j<m; j++){
            int x;
            cin>>x;
            arr[i] |= (1<<x);
        }
    }  

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((arr[i]&arr[j])==0)
                ans++;
        }
    }  

    cout<<ans;
    return 0;
}