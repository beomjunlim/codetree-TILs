#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m,t;
int arr[20][20];
int cnt[20][20];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    cin>>n>>m>>t;

    queue<pair<int,int>> marble;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        marble.push(make_pair(a-1,b-1));
    }


    for(int i=0; i<t; i++){
        int num = marble.size();
        memset(cnt, 0, sizeof(cnt));
        int nx;
        int ny;
        
        for(int j=0; j<num; j++){
            int x = marble.front().first;
            int y = marble.front().second;
            marble.pop();
            int number = 0;

            for(int k=0; k<4; k++){
                if(InRange(x+dx[k],y+dy[k])&&number<arr[x+dx[k]][y+dy[k]]){
                    number = arr[x+dx[k]][y+dy[k]];
                    nx = x + dx[k];
                    ny = y + dy[k];
                }
            }
            cnt[nx][ny]++;
        }

        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(cnt[j][k]==1)
                    marble.push(make_pair(j,k));
            }
        }

    }

    cout<<marble.size()<<'\n';
    return 0;
}