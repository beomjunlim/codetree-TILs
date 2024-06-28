#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int cnt = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int arr[26][26];
bool visited[26][26];
vector<int> town;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==1){
            visited[nx][ny] = true;
            cnt++;
            dfs(nx,ny);
        }
    }
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
            if(arr[i][j]==1&&!visited[i][j]){
                cnt = 1;
                visited[i][j] = true;
                dfs(i,j);
                town.push_back(cnt);
            }
        }
    }

    sort(town.begin(), town.end());

    cout<<town.size()<<'\n';

    for(int i=0; i<town.size(); i++){
        cout<<town[i]<<'\n';
    }
    return 0;
}