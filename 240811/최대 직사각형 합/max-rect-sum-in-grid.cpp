#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[301][301];
int sum[301][301];

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=n;
}

int Area(int low, int col, int x, int y){
    int num = 0;
    for(int i=x; i<x+low; i++){
        num += (sum[i][col+y-1] - sum[i][y-1]);
    }
    return num;
}

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
            sum[i][j] = sum[i][j-1] + arr[i][j];
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n-i+1; k++){
                for(int l=1; l<=n-j+1; l++){
                    ans = max(ans, Area(i,j,k,l));
                }
            }
        }
    }

    cout<<ans;
    return 0;
}