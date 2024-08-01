#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> arr[21][21];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            arr[i][j].push_back(num);
        }
    }

    for(int a=0; a<m; a++){
        int num;
        cin>>num;
        int pre_x;
        int pre_y;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<arr[i][j].size(); k++){
                    if(arr[i][j][k]==num){
                        pre_x = i;
                        pre_y = j;
                        break;
                    }
                }
            }
        }

        int next_x = -1;
        int next_y = -1;
        int max_num = -1;
        for(int i=0; i<8; i++){
            int nx = pre_x + dx[i];
            int ny = pre_y + dy[i];
            if(InRange(nx,ny)){
                for(int j=0; j<arr[nx][ny].size(); j++){
                    if(arr[nx][ny][j]>max_num){
                        max_num = arr[nx][ny][j];
                        next_x = nx;
                        next_y = ny;
                    }
                }
            }
        }
        bool to_move = false;

        if(next_x!=-1&&next_y!=-1){
            for(int i=0; i<arr[pre_x][pre_y].size(); i++){
                if(arr[pre_x][pre_y][i]==num)
                    to_move = true;
                if(to_move)
                    arr[next_x][next_y].push_back(arr[pre_x][pre_y][i]);
            }

            while(arr[pre_x][pre_y].back() != num)
                arr[pre_x][pre_y].pop_back();
            arr[pre_x][pre_y].pop_back();
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j].size()==0)
                cout<<"None";
            else{
                for(int k=arr[i][j].size() - 1; k>=0; k--)
                    cout<<arr[i][j][k]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}