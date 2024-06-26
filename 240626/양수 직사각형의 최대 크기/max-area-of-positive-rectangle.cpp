#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int ans = -1;
int arr[21][21];

bool InRange(int x, int y){
    return 0<=x&&x<n &&0<=y&&y<m;
}

int getArea(int a, int b, int low, int col){
    for(int i=a; i<=low; i++){
        for(int j=b; j<=col; j++){
            if(!InRange(i,j)||arr[i][j]<=0)
                return -1;
        }
    }
    return (low-a+1)*(col-b+1);
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int low=i; low<=n; low++){
                for(int col=j; col<=m; col++){
                    ans = max(ans, getArea(i,j,low,col));
                }
            }
        }
    }
    cout<<ans;
    return 0;
}