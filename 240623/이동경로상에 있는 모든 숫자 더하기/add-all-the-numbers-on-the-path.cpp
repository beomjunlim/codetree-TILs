#include <iostream>
using namespace std;

int n,t;
int arr[100][100];
char command[100001];
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

bool InRange(int x, int y){
    return 0<=x&& x<n && 0<=y && y<n;
}

int main() {
    cin>>n>>t;

    for(int i=0; i<t; i++){
        cin>>command[i];
    }    

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    int x = n/2, y = n/2;
    int sum = arr[x][y];
    int dir = 0;

    for(int i=0; i<t; i++){
        if(command[i]=='L'){
            dir = (dir+1)%4;
        }
        else if(command[i]=='R'){
            dir = (dir+3)%4;
        }
        else if(command[i]=='F'){
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(InRange(nx,ny)){
                sum += arr[nx][ny];
                x = nx;
                y = ny;
            }
        }
    }

    cout<<sum<<'\n';
    return 0;
}