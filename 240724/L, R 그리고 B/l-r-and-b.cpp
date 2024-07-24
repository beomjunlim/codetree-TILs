#include <iostream>
#include <queue>
using namespace std;

bool InRange(int x, int y){
    return 0<=x&&x<10&&0<=y&&y<10;
}

int main() {
    char arr[11][11];
    bool visited[11][11];

    pair<int,int> start;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            cin>>arr[i][j];
            if(arr[i][j]=='L'){
                start.first = i;
                start.second = j;
            }
        }
    }

    int cnt[11][11];
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    queue<pair<int,int>> q;
    q.push(make_pair(start.first, start.second));
    visited[start.first][start.second] = true;
    cnt[start.first][start.second] = 0;

    while(!q.empty()){
        int cur_i = q.front().first;
        int cur_j = q.front().second;
        q.pop();

        if(arr[cur_i][cur_j]=='B'){
            cout<<cnt[cur_i][cur_j] - 1;
            break;
        }

        for(int i=0; i<4; i++){
            int next_i = cur_i + dx[i];
            int next_j = cur_j + dy[i];

            if(InRange(next_i, next_j)&&arr[next_i][next_j]!='R'&&!visited[next_i][next_j]){
                q.push(make_pair(next_i, next_j));
                visited[next_i][next_j] = true;
                cnt[next_i][next_j] = cnt[cur_i][cur_j] + 1; 
            }
        }
    }


    return 0;
}