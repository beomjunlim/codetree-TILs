#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m,t,k;
vector<pair<int, pair<int,int>>> prev_marbles[51][51];
vector<pair<int, pair<int,int>>> next_marbles[51][51]; // num dir speed
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
    if(a.second.second == b.second.second)
        return a.first > b.first;
    return a.second.second > b.second.second;
}

int main() {
    cin>>n>>m>>t>>k;

    for(int i=1; i<=m; i++){
        int x,y,speed;
        char dir;
        cin>>x>>y>>dir>>speed;
        int direction;
        if(dir=='U')
            direction = 0;
        if(dir=='D')
            direction = 1;
        if(dir=='L')
            direction = 2;
        if(dir=='R')
            direction = 3;
        prev_marbles[x][y].push_back(make_pair(i, make_pair(direction,speed)));
    }

    int ans = m;
    for(int l=0; l<t; l++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(prev_marbles[i][j].size()!=0){
                    for(int s=0; s<prev_marbles[i][j].size(); s++){
                        int prev_x = i;
                        int prev_y = j;
                        int number = prev_marbles[i][j][s].first;
                        int direction = prev_marbles[i][j][s].second.first;
                        int speed = prev_marbles[i][j][s].second.second;

                        int next_x;
                        int next_y;
                        if(direction==0||direction==1){
                            int num = abs(speed*dx[direction]);
                            int x = prev_x;

                            for(int v=0; v<num; v++){
                                if(direction==0)
                                    x--;
                                else
                                    x++;
                                if(x==1)
                                    direction=1;
                                if(x==n)
                                    direction=0;
                            }
                            next_x = x;
                            next_y = prev_y;
                        }
                        else if(direction==2||direction==3){
                            int num = abs(speed*dy[direction]);
                            int y = prev_y;

                            for(int v=0; v<num; v++){
                                if(direction==2)
                                    y--;
                                else
                                    y++;

                                if(y==n)
                                    direction=2;
                                
                                if(y==1)
                                    direction=3;
                            }
                            next_y = y;
                            next_x = prev_x;
                        }
                        next_marbles[next_x][next_y].push_back(make_pair(number, make_pair(direction, speed)));
                    }
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                prev_marbles[i][j].clear();
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(next_marbles[i][j].size()>0){
                    sort(next_marbles[i][j].begin(), next_marbles[i][j].end(), cmp);
                    int cnt = next_marbles[i][j].size();

                    if(cnt>k){
                        ans -= (cnt-k);
                        cnt = k;
                    }

                    for(int s=0; s<cnt; s++){
                        int number = next_marbles[i][j][s].first;
                        int direction = next_marbles[i][j][s].second.first;
                        int speed = next_marbles[i][j][s].second.second;
                        prev_marbles[i][j].push_back(make_pair(number, make_pair(direction, speed)));
                    }
                }
            }
        }
    }

    cout<<ans;
    return 0;
}