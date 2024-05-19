#include <iostream>
using namespace std;

int n, r, c;
int arr[100][100];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void simulation(int x, int y){
    int num = arr[x][y];
    cout<<num<<" ";

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&num<arr[nx][ny]){
            simulation(nx,ny);
            break;
        }
    }
}


int main() {

    cin>>n>>r>>c;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    simulation(r-1,c-1);
    return 0;
}