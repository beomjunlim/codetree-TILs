#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int next_arr[51][51][4]; // U D L R
int arr[51][51][4];

int main() {
    int t;
    cin>>t;

    for(int k=0; k<t; k++){
        int n,m;
        cin>>n>>m;
        int cnt = m;
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<m; i++){
            int x,y;
            char dir;
            int cnt;
            cin>>x>>y>>dir;
            if(dir=='U')
                cnt = 0;
            if(dir=='D')
                cnt = 1;
            if(dir=='L')
                cnt = 2;
            if(dir=='R')
                cnt = 3;
            arr[x][y][cnt] = 1;
        }

        
        for(int l=0; l<2*n; l++){
            memset(next_arr, 0, sizeof(next_arr));
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(arr[i][j][0]==1){
                        if(i-1>=1)
                            next_arr[i-1][j][0]++;
                        else
                            next_arr[i][j][1]++;
                    }
                    if(arr[i][j][1]==1){
                        if(i+1<=n)
                            next_arr[i+1][j][1]++;
                        else
                            next_arr[i][j][0]++;

                    }
                    if(arr[i][j][2]==1){
                        if(j-1>=1)
                            next_arr[i][j-1][2]++;
                        else
                            next_arr[i][j][3]++;
                    }
                    if(arr[i][j][3]==1){
                        if(j+1<=n)
                            next_arr[i][j+1][3]++;
                        else
                            next_arr[i][j][2]++;

                    }
                }
            }
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    arr[i][j][0] = next_arr[i][j][0];
                    arr[i][j][1] = next_arr[i][j][1];
                    arr[i][j][2] = next_arr[i][j][2];
                    arr[i][j][3] = next_arr[i][j][3];
                    int num = arr[i][j][0] + arr[i][j][1] + arr[i][j][2] + arr[i][j][3];
                    if(num>1){
                        cnt -= num;
                        arr[i][j][0] = arr[i][j][1] = arr[i][j][2] = arr[i][j][3] = 0;
                    }
                }
            }
        }
        cout<<cnt<<'\n';
    } 
    return 0;
}