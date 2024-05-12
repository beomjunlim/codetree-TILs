#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = -1;
int arr[21][21];

void func(int x, int y, int x_size, int y_size){
    for(int i=x; i<x+x_size; i++){
        for(int j=y; j<y+y_size; j++){
            if(arr[i][j]<=0){
                return;
            }
        }
    }
    ans = max(ans, x_size*y_size);
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=0; k<=n-i; k++){
                for(int l=0; l<=m-j; l++){
                    func(k,l, i,j);
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}