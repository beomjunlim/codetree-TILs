#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[501][501];
int dp[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int main() {
    cin>>n;

    vector<pair<int, pair<int,int>>> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
            dp[i][j] = 1;
            v.push_back(make_pair(arr[i][j], make_pair(i,j)));
        }
    }

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        int x = v[i].second.first;
        int y = v[i].second.second;

        for(int j=0; j<4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];

            if(InRange(nx,ny)&&arr[nx][ny]>arr[x][y])
                dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
        }
    }

    int ans = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = max(ans, dp[i][j]);
        }
    }

    cout<<ans;
    return 0;
}