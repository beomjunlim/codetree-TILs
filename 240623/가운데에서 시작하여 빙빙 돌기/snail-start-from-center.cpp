#include <iostream>
using namespace std;

int n;
int arr[101][101];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

int main() {
    cin>>n;

    int x = n/2, y = n/2;

    arr[x][y] = 1;
    int dir = 0;
    int num = 1;
    int cnt = 0;
    int count = 0;

    for(int i=1; i<n*n; i++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        arr[nx][ny] = arr[x][y] + 1;
        x = nx;
        y = ny;
        cnt++;
        if(cnt==num){
            count++;
            cnt = 0;
            dir = (dir+1)%4;
        }

        if(count==2){
            count = 0;
            num++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}