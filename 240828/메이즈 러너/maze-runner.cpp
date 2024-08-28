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

struct Square{
    int square;
    int x;
    int y;
};

bool InRange(int x, int y){
    return 0<x&&x<=N&&0<y&&y<=N;
}

Square findSquare(){
    int square;
    int left_x;
    int left_y;
    for(int sq=2; sq<=N; sq++){
        square = sq;
        for(int i=1; i<=N; i++){
            left_x = i;
            for(int j=1; j<=N; j++){
                left_y = j;
                if(i<=R&&R<=i+sq-1&&j<=C&&C<=j+sq-1){
                    for(auto it : people){
                        int x = it.second.first;
                        int y = it.second.second;

                        if(i<=x&&x<=i+sq-1&&j<=y&&y<=j+sq-1){
                            return {square, left_x, left_y};
                        }
                    }
                }
            }
        }
    }
    return {square, left_x, left_y};
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

        if(people.size()==0)
            break;

        Square result = findSquare();

    //    cout<<"rotation "<<result.x<<" "<<result.y<<" "<<result.square<<'\n';
        rotation(result.x, result.y, result.square);

        for(auto &it : people){
            int x = it.second.first;
            int y = it.second.second;

            if(result.x<=x&&x<=result.x+result.square-1&&result.y<=y&&y<=result.y+result.square-1){
                int size = result.square;
                
                int d_x = x - result.x;
                int d_y = y - result.y;
                int nx = result.x + d_y;
                int ny = result.y + size - d_x - 1;

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