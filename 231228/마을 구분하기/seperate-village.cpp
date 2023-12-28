#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 25
int n;
int cnt =0;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false, };
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void DFS(int x, int y){
    visited[x][y] = true;
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(InRange(nx,ny)&&arr[nx][ny]==1&&!visited[nx][ny]){
            cnt+=1;
            DFS(nx,ny);
        }
    }
}

int main() {

    vector<int> v;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]==1 && !visited[i][j]){
                cnt=1;
                DFS(i,j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());
    cout<<v.size()<<'\n';
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<'\n';
    }
    return 0;
}