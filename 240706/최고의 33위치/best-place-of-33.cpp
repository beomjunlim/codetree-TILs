#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[21][21];

int check(int low, int col){
    int sum = 0;
    for(int i=low; i<low+3; i++){
        for(int j=col; j<col+3; j++){
            if(arr[i][j]==1)
                sum++;
        }
    }
    return sum;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int ans = 0;

    for(int i=0; i<=n-3; i++){
        for(int j=0; j<=n-3; j++){
            ans = max(ans, check(i,j));
        }
    }

    cout<<ans;
    return 0;
}