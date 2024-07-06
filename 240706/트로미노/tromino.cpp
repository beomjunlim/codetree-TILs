#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[201][201];
int ans = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void check(int low, int col){
    if(InRange(low+1, col+1)){
        int a = arr[low][col];
        int b = arr[low+1][col];
        int c = arr[low][col+1];
        int d = arr[low+1][col+1];
        int sum = max(a+b+c, max(a+b+d, max(b+c+d, a+c+d)));

        ans = max(sum,ans);
    }
    
    if(InRange(low+2, col)){
        int a = arr[low][col];
        int b = arr[low+1][col];
        int c = arr[low+2][col];
        ans = max(ans, a+b+c);
    }

    if(InRange(low, col+2)){
        int a = arr[low][col];
        int b = arr[low][col+1];
        int c = arr[low][col+2];
        ans = max(ans, a+b+c);
    }
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
            check(i,j);
        }
    }
    cout<<ans;
    return 0;
}