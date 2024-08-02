#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,t;
vector<pair<int, pair<int,int>>> prev_arr[51][51]; // num dir weight
vector<pair<int, pair<int,int>>> next_arr[51][51];

int main() {
    cin>>n>>m>>t;

    for(int i=1; i<=m; i++){
        int x,y,w;
        char d;
        cin>>x>>y>>d>>w;

        int dir;
        if(d=='U')
            dir = 0;
        if(d=='D')
            dir = 1;
        if(d=='L')
            dir = 2;
        if(d=='R')
            dir = 3;
        
        prev_arr[x][y].push_back(make_pair(i, make_pair(dir,w)));
    }

    for(int time=0; time<t; time++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                next_arr[i][j].clear();
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(prev_arr[i][j].size()>0){
                    int next_x = i;
                    int next_y = j;
                    int num = prev_arr[i][j][0].first;
                    int dir = prev_arr[i][j][0].second.first;
                    int weight = prev_arr[i][j][0].second.second;

                    if(dir==0){
                        next_x--;
                        if(next_x==0){
                            dir = 1;
                            next_x = 1;
                        }
                    }
                    else if(dir==1){
                        next_x++;
                        if(next_x>n){
                            dir = 0;
                            next_x = n;
                        }
                    }
                    else if(dir==2){
                        next_y--;
                        if(next_y==0){
                            dir = 3;
                            next_y = 1;
                        }
                    }
                    else if(dir==3){
                        next_y++;
                        if(next_y>n){
                            dir = 2;
                            next_y = n;
                        }
                    }

                    next_arr[next_x][next_y].push_back(make_pair(num, make_pair(dir, weight)));
                }
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                prev_arr[i][j].clear();
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(next_arr[i][j].size()>0){
                    int num = -1;
                    int dir = -1;
                    int weight = 0;

                    for(int k=0; k<next_arr[i][j].size(); k++){
                        weight += next_arr[i][j][k].second.second;
                        if(num < next_arr[i][j][k].first){
                            num = next_arr[i][j][k].first;
                            dir = next_arr[i][j][k].second.first;
                        }
                    }
                    prev_arr[i][j].push_back(make_pair(num, make_pair(dir,weight)));
                }
            }
        }
    }

    int cnt = 0;
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(prev_arr[i][j].size()>0){
                cnt++;
                ans = max(ans, prev_arr[i][j][0].second.second);
            }
        }
    }

    cout<<cnt<<" "<<ans;
    return 0;
}