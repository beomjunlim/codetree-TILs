#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100

int n,k;
int arr[MAX][MAX];
int cnt[MAX][MAX] = {0,};
bool visited[MAX][MAX] = {false,};
vector<pair<int,int>>v;
vector<int>ans;
int r1,r2,c1,c2;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

void Initialized(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = false;
            cnt[i][j] = 0;
        }
    }
}

void BFS(){
    queue<pair<int,int>>q;
    q.push(make_pair(r1-1,c1-1));
    visited[r1-1][c1-1] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if(cx==r2-1&&cy==c2-1){
            ans.push_back(cnt[cx][cy]);
            break;
        }

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(InRange(nx,ny)&&arr[nx][ny]==0&&!visited[nx][ny]){
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[cx][cy] + 1;
                q.push(make_pair(nx,ny));
            }
        }

    }
}

void BackT(int num, int start){
    if(num==k){
        BFS();
        Initialized();
        return;
    }

    for(int i=start; i<v.size(); i++){
        int x = v[i].first;
        int y = v[i].second;
        arr[x][y] = 0;
        BackT(num+1,start+1);
        arr[x][y] = 1;
    }
}

int main() {
    cin>>n>>k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                v.push_back(make_pair(i,j));
            }
        }
    }
    cin>>r1>>c1;
    cin>>r2>>c2;

    BackT(0,0);

    if(ans.empty())
        cout<<-1;
    else{
        sort(ans.begin(), ans.end());
        cout<<ans.front();
    }
    return 0;
}