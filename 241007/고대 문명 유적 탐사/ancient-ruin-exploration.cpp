#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct GOLD{
    int gold, angle, x, y;

    bool operator<(const GOLD & other) const{
        if(gold==other.gold){
            if(angle==other.angle){
                if(y==other.y)
                    return x > other.x;
                return y > other.y;
            }
            return angle > other.angle;
        }
        return gold < other.gold;
    }
};

int k,m;
int answer = 0;
int arr[5][5];
int temp[5][5];
bool zero[5][5];
bool visited[5][5];
int piece[301];
int pieceIdx = 0;
int dx[] = {1,1,1,2,2,2,3,3,3};
int dy[] = {1,2,3,1,2,3,1,2,3};
int nx[] = {0,0,-1,1};
int ny[] = {-1,1,0,0};



bool InRange(int x, int y){
    return 0<=x&&x<5&&0<=y&&y<5;
}

int getGold(int a, int b){
    visited[a][b] = true;
    queue<pair<int,int>> q;
    q.push({a,b});
    int num = temp[a][b];
    vector<pair<int,int>> v;
    v.push_back({a,b});
    int cnt = 1;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int cx = x + nx[i];
            int cy = y + ny[i];

            if(InRange(cx,cy)&&!visited[cx][cy]&&num==temp[cx][cy]){
                visited[cx][cy] = true;
                v.push_back({cx,cy});
                q.push({cx,cy});
                cnt++;
            }
        }
    }

    if(cnt>=3){
        for(int i=0; i<v.size(); i++){
            int x = v[i].first;
            int y = v[i].second;
            zero[x][y] = true;
        }
    }

    return cnt;
}

int firstGet(){
    memset(zero, false, sizeof(zero));
    memset(visited, false, sizeof(visited));
    int count = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(!visited[i][j]){
                int num = getGold(i,j);
                if(num>=3)
                    count += num;
            }
        }
    }
    return count;
}

int rotate(int x, int y, int angle){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            temp[i][j] = arr[i][j];
        }
    }

    if(angle==1){
        for(int i=0; i<3; i++){
            temp[x-1][y-1+i] = arr[x+1-i][y-1];
            temp[x-1+i][y+1] = arr[x-1][y-1+i];
            temp[x+1][y-1+i] = arr[x+1-i][y+1];
            temp[x-1+i][y-1] = arr[x+1][y-1+i];
        }
    }

    else if(angle==2){
        for(int i=0; i<3; i++){
            temp[x-1][y+1-i] = arr[x+1][y-1+i];
            temp[x-1+i][y+1] = arr[x+1-i][y-1];
            temp[x+1][y-1+i] = arr[x-1][y+1-i];
            temp[x+1-i][y-1] = arr[x-1+i][y+1];
        }
    }

    else if(angle==3){
        for(int i=0; i<3; i++){
            temp[x-1][y-1+i] = arr[x-1+i][y+1];
            temp[x-1+i][y+1] = arr[x+1][y+1-i];
            temp[x+1][y-1+i] = arr[x-1+i][y-1];
            temp[x-1+i][y-1] = arr[x-1][y+1-i];
        }
    }

    int count = firstGet();
    return count;
}

void makePiece(){
// cout<<"============123123====="<<'\n';
//     for(int i=0; i<5; i++){
//         for(int j=0; j<5; j++){
//             cout<<zero[i][j]<<" ";
//         }
//         cout<<'\n';
//     }
//     cout<<"=========2132313======="<<'\n';

    for(int j=0; j<5; j++){
        for(int i=4; i>=0; i--){
            if(zero[i][j]){
                temp[i][j] = piece[pieceIdx];
                pieceIdx++;
                if(pieceIdx==m)
                    pieceIdx = 0;
            }
        }
    }
    // cout<<"===================="<<'\n';
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<"===================="<<'\n';

    int num = firstGet();
    //cout<<"end "<<num<<'\n';
    if(num!=0){
        answer += num;
        makePiece();
    } 
}



int main() {
    cin>>k>>m;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<m; i++){
        cin>>piece[i];
    }

    while(k>0){
        priority_queue<GOLD> pq;
        answer = 0;

        for(int i=0; i<9; i++){ // 돌리기
            int cnt = rotate(dx[i],dy[i],1);
            pq.push({cnt,1,dx[i],dy[i]});
            
            cnt = rotate(dx[i],dy[i],2);
            pq.push({cnt,2,dx[i],dy[i]});

            cnt = rotate(dx[i],dy[i],3);
            pq.push({cnt,3,dx[i],dy[i]});
        }
        
        int num = pq.top().gold, angle = pq.top().angle, x = pq.top().x, y = pq.top().y;

        if(num==0)
            break;

        answer = rotate(x,y,angle);

        // cout<<"rotate"<<'\n';
        // for(int i=0; i<5; i++){
        //     for(int j=0; j<5; j++){
        //         cout<<temp[i][j]<<" ";
        //     }
        //     cout<<'\n';
        // }

        makePiece();
        cout<<answer<<" ";

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                arr[i][j] = temp[i][j];
            }
        }
        k--;
    }

    return 0;
}