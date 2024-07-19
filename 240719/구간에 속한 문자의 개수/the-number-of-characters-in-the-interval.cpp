#include <iostream>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;

    char arr[1001][1001];
    int sum[1001][1001][3];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    if(arr[1][1]=='a'){
        sum[1][1][0] = 1;
        sum[1][1][1] = 0;
        sum[1][1][2] = 0;
    }
    if(arr[1][1]=='b'){
        sum[1][1][0] = 0;
        sum[1][1][1] = 1;
        sum[1][1][2] = 0;
    }
    if(arr[1][1]=='c'){
        sum[1][1][0] = 0;
        sum[1][1][1] = 0;
        sum[1][1][2] = 1;
    }
    
    int a = 0;
    int b = 0;
    int c = 0;
    
    for(int i=2; i<=n; i++){
        if(arr[1][i]=='a'){
            a = 1;
            b = 0;
            c = 0;
        }
        if(arr[1][i]=='b'){
            a = 0;
            b = 1;
            c = 0;
        }
        if(arr[1][i]=='c'){
            a = 0;
            b = 0;
            c = 1;
        }   
        sum[1][i][0] = sum[1][i-1][0] + a;
        sum[1][i][1] = sum[1][i-1][1] + b;
        sum[1][i][2] = sum[1][i-1][2] + c;
    }

    for(int i=2; i<=n; i++){
        if(arr[i][1]=='a'){
            a = 1;
            b = 0;
            c = 0;
        }
        if(arr[i][1]=='b'){
            a = 0;
            b = 1;
            c = 0;
        }
        if(arr[i][1]=='c'){
            a = 0;
            b = 0;
            c = 1;
        }
        sum[i][1][0] = sum[i-1][1][0] + a;
        sum[i][1][1] = sum[i-1][1][1] + b;
        sum[i][1][2] = sum[i-1][1][2] + c;
    }

    for(int i=2; i<=n; i++){
        for(int j=2; j<=n; j++){
            if(arr[i][j]=='a'){
                a = 1;
                b = 0;
                c = 0;
            }
            if(arr[i][j]=='b'){
                a = 0;
                b = 1;
                c = 0;
            }
            if(arr[i][j]=='c'){
                a = 0;
                b = 0;
                c = 1;
            }
            sum[i][j][0] = a + sum[i-1][j][0] + sum[i][j-1][0] - sum[i-1][j-1][0];
            sum[i][j][1] = b + sum[i-1][j][1] + sum[i][j-1][1] - sum[i-1][j-1][1];
            sum[i][j][2] = c + sum[i-1][j][2] + sum[i][j-1][2] - sum[i-1][j-1][2];
        }
    }

    for(int i=0; i<k; i++){
        int x,y,z,k;
        cin>>x>>y>>z>>k;
        a = sum[z][k][0] - sum[x-1][k][0] - sum[z][y-1][0] + sum[x-1][y-1][0];
        b = sum[z][k][1] - sum[x-1][k][1] - sum[z][y-1][1] + sum[x-1][y-1][1];
        c = sum[z][k][2] - sum[x-1][k][2] - sum[z][y-1][2] + sum[x-1][y-1][2];
        cout<<a<<" "<<b<<" "<<c<<'\n';
    }
    return 0;
}