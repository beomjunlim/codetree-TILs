#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }    

    int cnt = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i-1][j]==0){
                cnt++;
                arr[i][j] ^= 1;
                for(int k=0; k<4; k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if(InRange(nx,ny)){
                        arr[nx][ny] ^= 1;
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==0){
                cnt = -1;
                break;
            }
        }
    }

    cout<<cnt;
    return 0;
}