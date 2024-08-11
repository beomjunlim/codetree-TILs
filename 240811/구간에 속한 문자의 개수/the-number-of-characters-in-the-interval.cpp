#include <iostream>
#include <algorithm>
using namespace std;

int sum[1001][1001][3];
char arr[1001][1001];

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }

    int a = 0,b = 0,c = 0;
    if(arr[1][1]=='a')
        a = 1;
    else if(arr[1][1]=='b')
        b = 1;
    else if(arr[1][1]=='c')
        c = 1;
    

    sum[1][1][0] = a;
    sum[1][1][1] = b;
    sum[1][1][2] = c;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int a = 0, b = 0, c = 0;
            if(arr[i][j]=='a')
                a = 1;
            if(arr[i][j]=='b')
                b = 1;
            if(arr[i][j]=='c')
                c = 1;
            sum[i][j][0] = sum[i-1][j][0] + sum[i][j-1][0] - sum[i-1][j-1][0] + a;
            sum[i][j][1] = sum[i-1][j][1] + sum[i][j-1][1] - sum[i-1][j-1][1] + b;
            sum[i][j][2] = sum[i-1][j][2] + sum[i][j-1][2] - sum[i-1][j-1][2] + c; 
        }
    }

    for(int i=0; i<k; i++){
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        int A = sum[r2][c2][0] - sum[r1-1][c2][0] - sum[r2][c1-1][0] + sum[r1-1][c1-1][0];
        int B = sum[r2][c2][1] - sum[r1-1][c2][1] - sum[r2][c1-1][1] + sum[r1-1][c1-1][1];
        int C = sum[r2][c2][2] - sum[r1-1][c2][2] - sum[r2][c1-1][2] + sum[r1-1][c1-1][2];
        cout<<A<<" "<<B<<" "<<C<<'\n';
    }
    return 0;
}