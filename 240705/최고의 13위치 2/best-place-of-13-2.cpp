#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int ans = 0;
int arr[21][21];
bool visited[21][21];
int dx[] = {0,0};
int dy[] = {1,2};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int choose(int x, int y){
    bool sw = true;
    int sum = 0;
    visited[x][y] = true;
    if(arr[x][y]==1)
        sum++;

    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = true;

        if(!InRange(nx,ny))
            sw = false;

        if(InRange(nx,ny)&&arr[nx][ny]==1)
            sum++;
    }

    if(sw)
        return sum;
    else
        return -1;
}

int choose_two(int x, int y){
    bool sw = true;
    int sum = 0 ;
    if(arr[x][y]==1)
        sum++;
    
    for(int i=0; i<2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(!InRange(nx,ny)||visited[nx][ny]){
            sw = false;
            break;
        }

        if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1)
            sum++;
    }

    if(!sw)
        return 0;
    else
        return sum;
}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num = choose(i,j);
            if(num!=-1){
                for(int k=0;k<n; k++){
                    for(int l=0; l<n; l++){
                        if(!visited[k][l]){
                            int num_two = choose_two(k,l);
                            if(num_two!=0){
                                ans = max(ans, num + num_two);
                            }
                        }
                    }
                }
            }
            memset(visited, false, sizeof(visited));
        }
    }

    cout<<ans;
    return 0;
}