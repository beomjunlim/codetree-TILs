#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
using namespace std;

struct Knight{
    int r;
    int c;
    int h;
    int w;
    int k;
};

int L,N,Q;
map<int, Knight> knights;
map<int, int> Damage;
int MAP[41][41];
bool visited[31];
bool deleted[31];
int knight_map[41][41];
int dx[] = {-1,0,1,0}; // 상 우 하 좌
int dy[] = {0,1,0,-1};

bool InRange(int x, int y){
    return 0<x&&x<=L&&0<y&&y<=L;
}

bool CanGo(int r, int c, int h, int w, int d, int id){
    if(d==0){
        int nr = r + dx[d];

        if(!InRange(nr,c)){
            return false;
        }
        for(int i=c; i<c+w; i++){
            if(MAP[nr][i]==2){
                return false;
            }
            int ID = knight_map[nr][i];
            if(ID!=0&&ID!=id&&!visited[ID]){
                visited[ID] = true;

                int Dr = knights[ID].r;
                int Dc = knights[ID].c;
                int Dh = knights[ID].h;
                int Dw = knights[ID].w;

                if(!CanGo(Dr, Dc, Dh, Dw, d, ID)){
                    return false;
                }
            }
        }
    }
    else if(d==1){
        int nc = c + w - 1 + dy[d];

        if(!InRange(r,nc))
            return false;

        for(int i=r; i<r+h; i++){
            if(MAP[i][nc]==2)
                return false;

            int ID = knight_map[i][nc];
            
            if(ID!=0&&ID!=id&&!visited[ID]){
                visited[ID] = true;

                int Dr = knights[ID].r;
                int Dc = knights[ID].c;
                int Dh = knights[ID].h;
                int Dw = knights[ID].w;

                if(!CanGo(Dr, Dc, Dh, Dw, d, ID)){
                    return false;
                }
            }
        }
    }
    else if(d==2){
        int nr = r + h - 1 + dx[d];

        if(!InRange(nr,c)){
            return false;
        }
        for(int i=c; i<c+w; i++){
            if(MAP[nr][i]==2){
                return false;
            }
            int ID = knight_map[nr][i];
            if(ID!=0&&ID!=id&&!visited[ID]){
                visited[ID] = true;

                int Dr = knights[ID].r;
                int Dc = knights[ID].c;
                int Dh = knights[ID].h;
                int Dw = knights[ID].w;

                if(!CanGo(Dr, Dc, Dh, Dw, d, ID)){
                    return false;
                }
            }
        }
    }
    else if(d==3){
        int nc = c + dy[d];

        if(!InRange(r,nc))
            return false;

        for(int i=r; i<r+h; i++){
            if(MAP[i][nc]==2)
                return false;

            int ID = knight_map[i][nc];
            
            if(ID!=0&&ID!=id&&!visited[ID]){
                visited[ID] = true;

                int Dr = knights[ID].r;
                int Dc = knights[ID].c;
                int Dh = knights[ID].h;
                int Dw = knights[ID].w;

                if(!CanGo(Dr, Dc, Dh, Dw, d, ID)){
                    return false;
                }
            }
        }
    }
    return true;
}

void move(int d){
    for(int id=1; id<=N; id++){
        if(!deleted[id]&&visited[id]){
            if(d==0||d==2){
                knights[id].r += dx[d];
            }
            else if(d==1||d==3){
                knights[id].c += dy[d];
            }
        }
    }
}

int main() {
    cin>>L>>N>>Q;

    for(int i=1; i<=L; i++){
        for(int j=1; j<=L; j++){
            cin>>MAP[i][j];
        }
    }

    for(int id=1; id<=N; id++){
        int r,c,h,w,k;
        cin>>r>>c>>h>>w>>k;
        knights[id] = Knight{r,c,h,w,k};
        for(int i=r; i<r+h; i++){
            for(int j=c; j<c+w; j++){
                knight_map[i][j] = id;
            }
        }
    }

    for(int q=1; q<=Q; q++){
        int id,d;
        cin>>id>>d;

        if(deleted[id])
            continue;

        int r = knights[id].r;
        int c = knights[id].c;
        int h = knights[id].h;
        int w = knights[id].w;

        memset(visited, false, sizeof(visited));
        
        if(CanGo(r,c,h,w,d,id)){

            if(d==0||d==2){
                knights[id].r += dx[d];
            }
            else if(d==1||d==3){
                knights[id].c += dy[d];
            }

            move(d);
            memset(knight_map, 0, sizeof(knight_map));
            set<int> deleted_knight;

            for(auto &it : knights){
                int ID = it.first;
                int r = it.second.r;
                int c = it.second.c;
                int h = it.second.h;
                int w = it.second.w;

                for(int i=r; i<r+h; i++){
                    for(int j=c; j<c+w; j++){
                        knight_map[i][j] = ID;

                        if(visited[ID]&&ID!=id){
                            if(MAP[i][j]==1){
                                it.second.k--;

                                Damage[ID]++;
                                if(it.second.k==0){
                                    deleted[ID] = true;
                                    deleted_knight.insert(ID);
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            for(auto ID : deleted_knight){
                knights.erase(ID);
                Damage.erase(ID);
            }
        }
    }

    int sum = 0;
    for(auto it : Damage){ 
        sum += it.second;
    }

    cout<<sum;
    return 0;
}