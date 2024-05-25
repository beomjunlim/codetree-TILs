#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int ans = 0;
int arr[20][20];
bool visited[20][20];
vector<pair<int,int>> bomb;
int type[10];
int kx[] = {-2,-1,1,2};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int nx[] = {-1,-1,1,1};
int ny[] ={-1,1,-1,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}


void backtracking(int num){
    if(num==bomb.size()){
        memset(visited, 0, sizeof(visited));
        int x,y;
        int cnt = 0;
        for(int i=0; i<num; i++){
            x = bomb[i].first;
            y = bomb[i].second;
            if(type[i]==1){
                if(!visited[x][y]){
                    visited[x][y] = true;
                    cnt++;
                }
                for(int j=0; j<4; j++){
                    if(InRange(x+kx[j],y)&&!visited[x+kx[j]][y]){
                        visited[x+kx[j]][y] = true;
                        cnt++;
                    }
                }
            }
            else if(type[i]==2){
                if(!visited[x][y]){
                    visited[x][y] = true;
                    cnt++;
                }
                for(int j=0; j<4; j++){
                    if(InRange(x+dx[j],y+dy[j])&&!visited[x+dx[j]][y+dy[j]]){
                        visited[x+dx[j]][y+dy[j]] = true;
                        cnt++;
                    }
                }

            }
            else if(type[i]==3){
                if(!visited[x][y]){
                    visited[x][y] = true;
                    cnt++;
                }
                for(int j=0; j<4; j++){
                    if(InRange(x+nx[j], y+ny[j])&&!visited[x+nx[j]][y+ny[j]]){
                        visited[x+nx[j]][y+ny[j]] = true;
                        cnt++;
                    }
                }
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for(int i=1; i<=3; i++){
        type[num] = i;
        backtracking(num+1);
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
    cout<<ans<<'\n';
    return 0;
}