#include <iostream>
using namespace std;

int n;
int arr[21][21];
int dx[] = {-1,-1,1,1};
int dy[] = {1,-1,-1,1};
int ans = 0;

bool InRange(int x, int y){
    return 0<=x&&x<n&&0<=y&&y<n;
}

int check(int x, int y, int k, int l){
    int move[] = {k,l,k,l};

    int sum = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<move[i]; j++){
            x += dx[i];
            y += dy[i];

            if(!InRange(x,y))
                return 0;
            sum += arr[x][y];
        }
    }
    return sum;
}


int main() {
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
                    ans = max(ans, check(i,j,k,l));
                }
            }
        }
    }
    cout<<ans;
    return 0;
}