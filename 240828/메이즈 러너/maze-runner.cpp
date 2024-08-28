#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
using namespace std;

int N,M,K,R,C;
int MAP[11][11];
bool visited[11];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
unordered_map<int, pair<int,int>> people;

bool InRange(int x, int y){
    return 0<x&&x<=N&&0<y&&y<=N;
}

void rotation(int x, int y, int s){
  //  cout<<x<<" "<<y<<" "<<s<<" hi"<<'\n';
    int temp[11][11] = {0};

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            temp[i][j] = MAP[i][j];
        }
    }

    for(int i=0; i<s; i++){
        for(int j=0; j<s; j++){
             if(MAP[x+i][y+j]>0)
                 MAP[x+i][y+j]--;
            temp[x+j][y+s-i-1] = MAP[x+i][y+j];
        }
    }

    

    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }

   for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            MAP[i][j] = temp[i][j];
            if(MAP[i][j]==-1){
                R = i;
                C = j;
            }
        }
    }    

    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++){
    //         cout<<MAP[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}

int main() {
    cin>>N>>M>>K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>MAP[i][j];
        }
    }

    for(int i=1; i<=M; i++){
        int r,c;
        cin>>r>>c;
        people[i] = make_pair(r,c);
    }

    int sum = 0;
    int r,c;
    cin>>R>>C;
    MAP[R][C] = -1;

    while(K>0){
        memset(visited, false, sizeof(visited));
        for(auto &it : people){
            int x = it.second.first;
            int y = it.second.second;

            int dist = 2*N;
            int next_x = x;
            int next_y = y;
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                int num = abs(nx-x) + abs(ny-y);
                int A = abs(x-R) + abs(y-C);
                int B = abs(nx-R) + abs(ny-C);

                if(InRange(nx,ny)&&MAP[nx][ny]<=0&&num<dist&&A>B){
                    dist = num;
                    next_x = nx;
                    next_y = ny;
                }
            }

            sum += abs(x-next_x) + abs(y-next_y);

            if(MAP[next_x][next_y]==-1){
                visited[it.first] = true;
            }
            else
                people[it.first] = make_pair(next_x, next_y);
        }

        for(int i=1; i<=M; i++){
            if(visited[i]){
                people.erase(i);
            }
        }   

        int left_x = N+1;
        int left_y = N+1;
        int squaure = N+1;

        if(people.size()==0)
            break;

        for(auto it : people){
            int x = it.second.first;
            int y = it.second.second;

           // cout<<"People "<<x<<" "<<y<<" "<<R<<" "<<C<<'\n';

            int dist = max(abs(R-x), abs(C-y));

            // 좌측 상단
            int nx = max(R - dist,1);
            int ny = max(C - dist,1);

            if(InRange(nx,ny)&&nx<=x&&x<=nx+dist&&ny<=y&&y<=ny+dist){
                if(squaure>dist){
                    left_x = nx;
                    left_y = ny;
                    squaure = dist;
                }

                if(squaure==dist){
                    if(left_x>nx){
                        left_x = nx;
                        left_y = ny;
                    }
                    if(left_x==nx){
                        if(left_y>ny)
                            left_y = ny;
                    }
                }
            }

            // 우측 상단

            nx = max(R - dist,1);
            ny = C;

            if(InRange(nx,ny)&&nx<=x&&x<=nx+dist&&ny<=y&&y<=ny+dist){
                if(squaure>dist){
                    left_x = nx;
                    left_y = ny;
                    squaure = dist;
                }

                if(squaure==dist){
                    if(left_x>nx){
                        left_x = nx;
                        left_y = ny;
                    }
                    if(left_x==nx){
                        if(left_y>ny)
                            left_y = ny;
                    }
                }
            }

            // 좌측 하단

            nx = R;
            ny = max(C - dist,1);

            if(InRange(nx,ny)&&nx<=x&&x<=nx+dist&&ny<=y&&y<=ny+dist){
                if(squaure>dist){
                    left_x = nx;
                    left_y = ny;
                    squaure = dist;
                }

                if(squaure==dist){
                    if(left_x>nx){
                        left_x = nx;
                        left_y = ny;
                    }
                    if(left_x==nx){
                        if(left_y>ny)
                            left_y = ny;
                    }
                }
            }

            // 우측 하단

            nx = R;
            ny = C;

            if(InRange(nx,ny)&&nx<=x&&x<=nx+dist&&ny<=y&&y<=ny+dist){
                if(squaure>dist){
                    left_x = nx;
                    left_y = ny;
                    squaure = dist;
                }

                if(squaure==dist){
                    if(left_x>nx){
                        left_x = nx;
                        left_y = ny;
                    }
                    if(left_x==nx){
                        if(left_y>ny)
                            left_y = ny;
                    }
                }
            }
           // cout<<"후보군 "<<left_x<<" "<<left_y<<" "<<squaure<<'\n';
        }


        rotation(left_x, left_y, squaure+1);
   //     cout<<"rotation "<<left_x<<" "<<left_y<<" "<<squaure+1<<'\n';

        for(auto &it : people){
            int x = it.second.first;
            int y = it.second.second;

            if(left_x<=x&&x<=left_x+squaure&&left_y<=y&&y<=left_y+squaure){
                int size = squaure + 1;
                
                int d_x = x - left_x;
                int d_y = y - left_y;
                int nx = left_x + d_y;
                int ny = left_y + size - d_x - 1;

                //cout<<"people "<<it.first<<" "<<nx<<" "<<ny<<'\n';
                people[it.first] = make_pair(nx,ny);
            }
        }

        K--;
    }

    // cout<<people.size()<<'\n';
    // for(auto it : people){
    //     cout<<it.second.first<<" "<<it.second.second<<'\n';
    // }

    cout<<sum<<'\n';
    cout<<R<<" "<<C<<'\n';
    return 0;
}