#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <cstring>
#include <map>
using namespace std;

struct People {
    int x, y, dir;
    bool sw;
};

int answer = 0;
int n, m, h, K;
int X, Y, Dir;
int Map[101][101];
People people[10001];
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

bool InRange(int x, int y) {
    return 0 < x && x <= n && 0 < y && y <= n;
}

int main() {
    cin >> n >> m >> h >> K;

    for (int i = 1; i <= m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        people[i] = { x,y,d, false };
    }

    for (int i = 0; i < h; i++) {
        int x, y;
        cin >> x >> y;
        Map[x][y] = 10;
    }

    X = n / 2 + 1;
    Y = n / 2 + 1;
    Dir = 0;
    int step = 1;
    int count = 0;
    int move = 0;
    int num = 1;


    for (int k = 1; k <= K; k++) {
        vector<int> temp[101][101];
        for (int i = 1; i <= m; i++) {
            //cout<<people[i].x<<" "<<people[i].y<<" "<<people[i].sw<<'\n';
            if (people[i].sw)
                continue;

            int x = people[i].x;
            int y = people[i].y;
            int dir = people[i].dir;
        
         //   cout<<"k "<<k<<" "<<abs(X-x) + abs(Y-y)<<" "<<x<<" "<<y<<" X "<<X<<" "<<Y<<'\n';
            if (abs(X - x) + abs(Y - y) > 3)
                continue;

            int nx = x + dx[dir], ny = y + dy[dir];
           // cout<<"k "<<k<<" x "<<nx<<" y "<<ny<<'\n';
            if(nx==X&&ny==Y)
                continue;
            if(!InRange(nx, ny)){
                dir = (dir+2)%4;
                nx = x + dx[dir];
                ny = y + dy[dir];
                if(nx==X&&ny==Y){
                    nx =x;
                    ny =y;
                }
            }
            // if (dir == 1) { // ->
            //     if (!InRange(nx, ny + )) {
            //         dir = (dir + 2) % 4;
                    
            //     }

            // }
            // else if (dir == 2) { // v
            //     if (!InRange(nx + 1, ny)) {
            //         dir = (dir + 2) % 4;
            //         nx--;
            //     }
            //     else
            //         nx++;

            //     if (nx == X && ny == Y)
            //         nx = x;
            // }
         //   cout<<nx<<" "<<ny<<'\n';
            people[i] = { nx,ny,dir,false };
         //   cout<<"k "<<k<<" x "<<x<<" y "<<y<<'\n';
        }
        
        for(int i=1; i<=m; i++){
            if(!people[i].sw)
                temp[people[i].x][people[i].y].push_back(i);
        }

        X += dx[Dir];
        Y += dy[Dir];
        move++;

        if (move == step) {
            move = 0;
            count++;
            if (num > 0)
                Dir = (Dir + 1) % 4;
            else
                Dir = (4 + Dir - 1) % 4;

            if (step == n - 1) {
                if (count == 3&&num>0) {
                    Dir = (Dir + 1) % 4;
                    count = 0;
                    num = -num;
                }
                else if (count == 3 && num < 0) {
                    step += num;
                    count = 0;
                }
            }
            else {
                if (count == 2) {
                    count = 0;
                    step += num;
                }
                if (X == n / 2 + 1 && Y == n / 2 + 1) {
                    Dir = (4 + Dir - 1) % 4;
                    num = -num;
                    step = 1;
                }
            }
        }

        int Catch = 0;
        for (int i = 0; i < 3; i++) {
            int NX = X + i * dx[Dir];
            int NY = Y + i * dy[Dir];

            if (!InRange(NX, NY))
                continue;
            if (!temp[NX][NY].empty() && Map[NX][NY] == 0) {
                Catch += temp[NX][NY].size();
               // cout<<temp[NX][NY].size()<<'\n';
                for (int j = 0; j < temp[NX][NY].size(); j++) {
                    people[temp[NX][NY][j]].sw = true;
                }
            }
        }
        answer += k * Catch;
    }

    // cout<<"X "<<X<<" "<<Y<<" "<<Dir<<'\n';
    // for(int i=1; i<=m; i++){
    //     cout<<people[i].x<<" "<<people[i].y<<" "<<people[i].sw<<'\n';
    // }
    cout << answer;
    return 0;
}