#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

int n,m,k;
int arr[11][11];
int attack[11][11];
bool visited[11][11];
int dx[] = {0,1,0,-1,-1,-1,1,1};
int dy[] = {1,0,-1,0,-1,1,-1,1};
priority_queue<pair<int, pair<int, pair<int, int>>>> small_turret; // 공격력 낮은, 가장 최근 공격, 행 열 합 높은, 열 높은
priority_queue<pair<int, pair<int, pair<int, int>>>> big_turret; // 공격력 높은, 가장 오래 전 공격, 행 열 합 낮은, 열 낮은

bool InRange(int x, int y){
    return 0<x&&x<=n&&0<y&&y<=m;
}

int main() {
    cin>>n>>m>>k;

    set<pair<int,int>> node;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
            attack[i][j] = 0;
            int sum = i + j;
            if(arr[i][j]!=0){
                small_turret.push(make_pair(-arr[i][j], make_pair(attack[i][j], make_pair(sum, j))));
                big_turret.push(make_pair(arr[i][j], make_pair(-attack[i][j], make_pair(-sum, -j))));
                node.insert(make_pair(i,j));
            }
        }
    }

    for(int sequence=1; sequence<=k; sequence++){
        int attack_power = -small_turret.top().first;
        int attack_x = small_turret.top().second.second.first - small_turret.top().second.second.second;
        int attack_y = small_turret.top().second.second.second;

        int defence_power = big_turret.top().first;
        int defence_x = -(big_turret.top().second.second.first - big_turret.top().second.second.second);
        int defence_y = -big_turret.top().second.second.second;

        if(attack_x==defence_x&&attack_y==defence_y)
            break;

        node.erase(make_pair(attack_x,attack_y)); // 공격자 제외
        

        small_turret = priority_queue<pair<int, pair<int, pair<int, int>>>> (); // 초기화
        big_turret = priority_queue<pair<int, pair<int, pair<int, int>>>> (); // 초기화

        
        attack_power += (n+m);
        arr[attack_x][attack_y] = attack_power;
        
        memset(visited, 0, sizeof(visited));
        bool sw = false;

        queue<pair<int,int>> q;
        q.push(make_pair(attack_x, attack_y));
        visited[attack_x][attack_y] = true;
        pair<int,int> prev_node[11][11]; // 방문 경로를 저장하는 배열
        vector<pair<int,int>> path;

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(x==defence_x&&y==defence_y){
                while(true){
                    if(x==attack_x&&y==attack_y)
                        break;

                    path.push_back(make_pair(x,y));
                    tie(x,y) = prev_node[x][y];  
                }

                sw = true;
                break;
            }
            
            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(InRange(nx,ny)){ // 범위 벗어나지 않을 경우
                    if(!visited[nx][ny]&&arr[nx][ny]!=0){
                        visited[nx][ny] = true;
                        prev_node[nx][ny] = make_pair(x,y);
                        q.push(make_pair(nx,ny));
                    }
                }
                else{ // 벗어날 경우
                    if(nx>n)
                        nx = 1;
                    if(nx==0)
                        nx = n;
                    if(ny>m)
                        ny = 1;
                    if(ny==0)
                        ny = m;

                    if(!visited[nx][ny]&&arr[nx][ny]!=0){
                        visited[nx][ny] = true;
                        prev_node[nx][ny] = make_pair(x,y);
                        q.push(make_pair(nx,ny));
                    }
                }
            }
        }


        if(sw){ // 레이저 공격
            int half_power = attack_power / 2;
            for(int i=0; i<path.size(); i++){
                int x = path[i].first;
                int y = path[i].second;

                if(x==attack_x&&y==attack_y)
                    continue;

                if(x==defence_x&&y==defence_y)
                    arr[x][y] = max(0, arr[x][y] - attack_power);
                else
                    arr[x][y] = max(0, arr[x][y] - half_power);
                node.erase(make_pair(x,y));
            }
        }
        else{ // 포탄 공격
            int half_power = attack_power / 2;
            int x = defence_x;
            int y = defence_y;

            arr[x][y] = max(0, arr[x][y] - attack_power);
            node.erase(make_pair(x,y));

            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx==attack_x&&ny==attack_y)
                    continue;

                if(InRange(nx,ny)){
                    if(arr[nx][ny]!=0){
                        arr[nx][ny] = max(0, arr[nx][ny] - half_power);
                        node.erase(make_pair(nx,ny));
                    }
                }
                else{
                    if(nx>n&&ny>m){
                        nx = 1;
                        ny = 1;
                    }
                    else if(nx==0&&ny==0){
                        nx = n;
                        ny = m;
                    }
                    else if(nx>n&&ny==0){
                        nx = 1;
                        ny = m;
                    }
                    else if(nx==0&&ny>m){
                        nx = n;
                        ny = 1;
                    }
                    else if(nx>n&&ny<=m&&ny>0){
                        nx = 1;
                    }
                    else if(nx==0&&ny<=m&&ny>0){
                        nx = n;
                    }
                    else if(ny>m&&nx<=n&&nx>0){
                        ny = 1;
                    }
                    else if(ny==0&&nx<=n&&nx>0){
                        ny = m;
                    }

                    if(nx==attack_x&&ny==attack_y)
                        continue;

                    if(arr[nx][ny]!=0){
                        arr[nx][ny] = max(0, arr[nx][ny] - half_power);
                        node.erase(make_pair(nx,ny));
                    }
                }
            }
        }

        for(auto it : node){
            int x = it.first;
            int y = it.second;

            arr[x][y]++;
        }

        node.clear();

        attack[attack_x][attack_y] = sequence;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                int sum = i + j;

                if(arr[i][j]!=0){
                    small_turret.push(make_pair(-arr[i][j], make_pair(attack[i][j], make_pair(sum, j))));
                    big_turret.push(make_pair(arr[i][j], make_pair(-attack[i][j], make_pair(-sum, -j))));
                    node.insert(make_pair(i,j));
                }
            }
        }
    }

    cout<<big_turret.top().first;
    return 0;
}