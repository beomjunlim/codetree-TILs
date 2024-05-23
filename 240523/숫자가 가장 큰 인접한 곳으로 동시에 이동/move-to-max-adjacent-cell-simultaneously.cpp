#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n,m,t;
int arr[21][21];
int cnt[21][21];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

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

        
        for(int j=0; j<num; j++){
            int nx = -1;
            int ny = -1;
            int x = marble.front().first;
            int y = marble.front().second;
            marble.pop();
            int number = 0;

            for(int k=0; k<4; k++){
                int newX = x + dx[k];
                int newY = y + dy[k];
                if(InRange(newX, newY)&&number<arr[newX][newY]){
                    number = arr[newX][newY];
                    nx = newX;
                    ny = newY;
                }
            }
            if(nx!=-1&&ny!=-1)
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