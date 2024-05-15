#include <iostream>
using namespace std;

int n,r,c,m1,m2,m3,m4,dir;
int arr[101][101];

int main() {
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>arr[i][j];
        }
    }

    cin>>r>>c>>m1>>m2>>m3>>m4>>dir;
    
    if(dir==0){
        int temp = arr[r][c];
        for(int i=0; i<m4; i++){
            arr[r-i][c-i] = arr[r-i-1][c-i-1];
        }

        for(int i=0; i<m3; i++){
            arr[r-m4-i][c-m4+i] = arr[r-m4-i-1][c-m4+i+1];
        }

        for(int i=0; i<m2; i++){
            arr[r-m1-m2+i][c+m1-m2+i] = arr[r-m1-m2+i+1][c+m1-m2+i+1];
        }

        for(int i=0; i<m1-1; i++){
            arr[r-m1+i][c+m1-i] = arr[r-m1+i+1][c+m1-i-1];
        }
        arr[r-1][c+1] = temp;
    }

    else if(dir==1){
        int temp = arr[r][c];
        for(int i=0; i<m1; i++){
            arr[r-i][c+i] = arr[r-i-1][c+i+1];
        }

        for(int i=0; i<m2; i++){
            arr[r-m1-i][c+m1-i] = arr[r-m1-i-1][c+m1-i+1]; 
        }

        for(int i=0; i<m3; i++){
            arr[r-m1-m2+i][c+m1-m2-i] = arr[r-m1-m2+i+1][c+m1-m2-i-1];
        }

        for(int i=0; i<m4-1; i++){
            arr[r-m4-i][c-m4+i] = arr[r-m4-i-1][c-m4+i+1];
        }
        arr[r-1][c-1] = temp;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}