#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,k;
int ans = 0;
int arr[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int,int>> start;
vector<pair<int,int>> rock;
int rock_arr[9];


bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    int number = 0;
    queue<pair<int,int>> q;
    memset(visited, false, sizeof(visited));

    for(int i=0; i<start.size(); i++){
        int x = start[i].first;
        int y = start[i].second;
        visited[x][y] = true;
        number++;
        q.push(make_pair(x,y));
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]==0){
                q.push(make_pair(nx,ny));
                number++;
                visited[nx][ny] = true;
            }
        }
    }
    ans = max(ans, number);
}

void backtracking(int num, int cnt){
    if(cnt==m){
        for(int i=0; i<m; i++){
            int x = rock[rock_arr[i]].first;
            int y = rock[rock_arr[i]].second;
            arr[x][y] = 0;
        }

        bfs();

        for(int i=0; i<m; i++){
            int x = rock[rock_arr[i]].first;
            int y = rock[rock_arr[i]].second;
            arr[x][y] = 1;
        }
        return;
    }

    for(int i=num; i<rock.size(); i++){
        rock_arr[cnt] = i;
        backtracking(i+1, cnt+1);
    }
}

int main() {
    cin>>n>>k>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                rock.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0; i<k; i++){
        int a,b;
        cin>>a>>b;
        start.push_back(make_pair(a-1,b-1));
    }

    backtracking(0,0);

    cout<<ans;
    return 0;
}