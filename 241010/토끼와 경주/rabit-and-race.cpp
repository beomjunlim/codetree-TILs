#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>

using namespace std;

struct Rabit {
    int id, jump, r, c;
};

int n, m, p;
Rabit rabit[2001];
map<int, int> RabitJump;
map<int, long long> Score;
bool jumping[2001];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };

bool Jump(Rabit a, Rabit b) {
    if (a.jump != b.jump)
        return a.jump < b.jump;
    if (a.r + a.c != b.r + b.c)
        return a.r + a.c < b.r + b.c;
    if (a.r != b.r)
        return a.r < b.r;
    if (a.c != b.c)
        return a.c < b.c;
    return a.id < b.id;
}

bool Give(Rabit a, Rabit b) {
    if (a.r + a.c != b.r + b.c)
        return a.r + a.c > b.r + b.c;
    if (a.r != b.r)
        return a.r > b.r;
    if (a.c != b.c)
        return a.c > b.c;
    return a.id > b.id;
}

bool choice(pair<int, int> a, pair<int, int> b) {
    if (a.first + a.second != b.first + b.second)
        return a.first + a.second > b.first + b.second;
    if (a.first != b.first)
        return a.first > b.first;
    if (a.second != b.second)
        return a.second > b.second;
}

int main() {
    int Q;
    cin >> Q;

    while (Q > 0) {
        int cmd;
        cin >> cmd;

        if (cmd == 100) {
            cin >> n >> m>>p;
            for (int i = 0; i < p; i++) {
                int id, d;
                cin >> id >> d;
                rabit[i] = { id, 0,1,1 };
                RabitJump[id] = d;
            }
        }
        else if (cmd == 200) {
            int k, s;
            cin >> k >> s;
            
            memset(jumping, false, sizeof(jumping));
            for (int i = 0; i < k; i++) {
                sort(rabit, rabit+p, Jump);
                vector<pair<int, int>> arr;

                for (int j = 0; j < 4; j++) {
                    int nx = abs(RabitJump[rabit[0].id] * dx[j]);
                    int ny = abs(RabitJump[rabit[0].id] * dy[j]);

                    nx = nx%(2*n-2);
                    ny = ny%(2*m-2);
                    int x = rabit[0].r;
                    int y = rabit[0].c;
                    int dir = j;
                    for(int w=1; w<=nx; w++){
                        x += dx[dir];

                        if(x==0||x==n+1){
                            dir = (dir+2)%4;
                            if(x==0)
                                x = 2;
                            else
                                x = n-1;
                        }
                    }

                    for(int w=1; w<=ny; w++){
                        y += dy[dir];
                        if(y==0||y==m+1){

                            dir = (dir+2)%4;
                            if(y==0)
                                y = 2;
                            else
                                y = m-1;
                        }
                    }
                    arr.push_back({ x,y });
                }

                sort(arr.begin(), arr.end(), choice);

                rabit[0].r = arr[0].first;
                rabit[0].c = arr[0].second;
                jumping[rabit[0].id] = true;
                rabit[0].jump++;

                for (int j = 1; j < p; j++) {
                    int id = rabit[j].id;
                    Score[id] += (rabit[0].r + rabit[0].c);
                }
            }

            sort(rabit, rabit + p, Give);
            for (int i = 0; i < p; i++) {
                if (jumping[rabit[i].id]) {
                    Score[rabit[i].id] += s;
                    break;
                }
            }

            
        }
        else if (cmd == 300) {
            int id, l;
            cin >> id >> l;
            int num = RabitJump[id];
            RabitJump[id] = num * l;

        }
        else if (cmd == 400) {
            long long answer = 0;
            for (auto it : Score) {
                if (it.second > answer)
                    answer = it.second;
            }
            cout << answer;
        }
        Q--;
    }
    return 0;
}