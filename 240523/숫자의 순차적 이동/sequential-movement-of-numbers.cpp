#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[20][20];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
pair<int,int> num[401];

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void change(int x, int y){
    int max_num = 0;
    int change_x = -1;
    int change_y = -1;
    for(int i=0; i<8; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&max_num < arr[nx][ny]){
            max_num = arr[nx][ny];
            change_x = nx;
            change_y = ny;
        }
    }
    
    num[arr[x][y]].first = change_x;
    num[arr[x][y]].second = change_y;
    num[max_num].first = x;
    num[max_num].second = y;
    swap(arr[x][y], arr[change_x][change_y]);
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            num[arr[i][j]].first = i;
            num[arr[i][j]].second = j;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=1; j<=n*n; j++){
            change(num[j].first, num[j].second);
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