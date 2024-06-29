#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k;
vector<pair<int,int>> orange;
int arr[101][101];
int cnt[101][101];
bool visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void bfs(){
    queue<pair<int, pair<int,int>>> q;
    for(int i=0; i<orange.size(); i++){
        int x = orange[i].first;
        int y = orange[i].second; 
        q.push(make_pair(0, make_pair(x,y)));
        visited[x][y] = true;
    }

    while(!q.empty()){
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int count = q.front().first;
        q.pop();

        if(arr[cx][cy]==1){
            cnt[cx][cy] = count;
        }
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(InRange(nx,ny)&&!visited[nx][ny]&&arr[nx][ny]!=0){
                visited[nx][ny] = true;
                q.push(make_pair(count+1, make_pair(nx,ny)));
            }
        }
    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];

            // if(arr[i][j]==1){
            //     orange.push_back(make_pair(i,j));
            // }
            if(arr[i][j]==0){
                cnt[i][j] = -1;
            }
            else if(arr[i][j]==2){
                cnt[i][j] = 0;
                orange.push_back(make_pair(i,j));
            }
        }
    }

    bfs();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]&&arr[i][j]!=0){
                cout<<-2<<" ";
            }
            else{
                cout<<cnt[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}