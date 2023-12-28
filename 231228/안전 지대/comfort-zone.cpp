#include <iostream>
using namespace std;

#define MAX 50

int n,m;
int num =0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<m;
}

void InitializeVisited(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j] = false;
        }
    }
}

void DFS(int x, int y, int k){
    visited[x][y] = true;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]>k)
            DFS(nx,ny,k);
    }
}

void GetArea(int k){
    num = 0;
    InitializeVisited();

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]>k&&!visited[i][j]){
                num+=1;
                DFS(i,j,k);
            }
        }
    }
}


int main() {
    int k=0;
    int max_area = 0;
    int max_k = 1;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            if(k<arr[i][j])
                k=arr[i][j];
        }
    }

    for(int i=1; i<k; i++){
        GetArea(i);
        if(max_area<num){
            max_area = num;
            max_k = i;
        }
    }

    cout<<max_k<<" "<<max_area;
    return 0;
}