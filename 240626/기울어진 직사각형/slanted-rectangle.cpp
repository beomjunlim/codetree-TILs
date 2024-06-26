#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[21][21];
int dx[] = {-1,-1,1,1};
int dy[] = {1,-1,-1,1};

bool InRange(int x, int y){
    return 0<=x&&x<n && 0<=y&&y<n;
}

int getNum(int low, int col, int k, int l){
    int num = 0;
    int move_num[] = {k,l,k,l};

    for(int i=0; i<4; i++){
        for(int j=0; j<move_num[i]; j++){
            low += dx[i];
            col += dy[i];
            if(!InRange(low,col))
                return 0;
            num += arr[low][col];
        }
    }
    return num;
}

int main() {
    int ans = 0;
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=1; k<n; k++){
                for(int l=1; l<n; l++){
                    ans = max(ans, getNum(i,j,k,l));
                }
            }
        }
    }
    cout<<ans;
    return 0;
}