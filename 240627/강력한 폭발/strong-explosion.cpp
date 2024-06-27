#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int ans = 0;
int arr[21][21];
bool visited[21][21];
vector<pair<int,int>> bomb;
int bombs[11];
int dx_b[] = {0,0,-1,1};
int dy_b[] = {-1,1,0,0};
int dx_c[] = {-1,-1,1,1};
int dy_c[] = {-1,1,-1,1};

bool InRange(int x, int y){
    return 0<=x&&x<n &&0<=y&&y<n;
}

int check(){
    int num = 0;
    for(int i=0; i<bomb.size(); i++){
        if(bombs[i]==1){
            int x = bomb[i].first;
            int y = bomb[i].second;
            
            if(!visited[x][y]){
                visited[x][y] = true;
                num++;
            }

            for(int j=1; j<3; j++){
                if(InRange(x-j,y)&&!visited[x-j][y]){
                    visited[x-j][y] = true;
                    num++;
                }

                if(InRange(x+j,y)&&!visited[x+j][y]){
                    visited[x+j][y] = true;
                    num++;
                }
            }
        }
        else if(bombs[i]==2){
            int x = bomb[i].first;
            int y = bomb[i].second;

            if(!visited[x][y]){
                visited[x][y] = true;
                num++;
            }

            for(int j=0; j<4; j++){
                int nx = x + dx_b[j];
                int ny = y + dy_b[j];

                if(InRange(nx,ny)&&!visited[nx][ny]){
                    visited[nx][ny] = true;
                    num++;
                }
            }

        }
        else if(bombs[i]==3){
            int x = bomb[i].first;
            int y = bomb[i].second;

            if(!visited[x][y]){
                visited[x][y] = true;
                num++;
            }

            for(int j=0; j<4; j++){
                int nx = x + dx_c[j];
                int ny = y + dy_c[j];

                if(InRange(nx,ny)&&!visited[nx][ny]){
                    visited[nx][ny] = true;
                    num++;
                }
            }
        }
    }
    return num;
}

void backtracking(int cnt){
    if(cnt==bomb.size()){
        memset(visited, false, sizeof(visited));
        ans = max(ans, check());
        return;
    }

    for(int i=1; i<=3; i++){
        bombs[cnt] = i;
        backtracking(cnt+1);
    }

}

int main() {
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                bomb.push_back(make_pair(i,j));
            }
        }
    }

    backtracking(0);
    cout<<ans;
    return 0;
}